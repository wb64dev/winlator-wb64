#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#include "sys/shm.h"

#define REQUEST_CODE_SHMGET 0
#define REQUEST_CODE_GET_FD 1
#define REQUEST_CODE_DELETE 2

#define MIN_REQUEST_LENGTH 5
#define ROUND_UP(N, S) ((((N) + (S) - 1) / (S)) * (S))

/* based on https://github.com/pelya/android-shmem */

typedef struct {
    int id;
    void* addr;
    int fd;
    size_t size;
    char marked_for_delete;
} shmemory_t;

static shmemory_t* shmemories = NULL;
static int shmemory_count = 0;
static int sysvshm_server_fd = -1;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int find_shmemory_index(int shmid) {
    for (int i = 0; i < shmemory_count; i++) if (shmemories[i].id == shmid) return i;
    return -1;
}

static void sysvshm_connect() {
    if (sysvshm_server_fd >= 0) return;
    char* path = getenv("ANDROID_SYSVSHM_SERVER");
    
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) return;
    
    struct sockaddr_un server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_LOCAL;
    
    strncpy(server_addr.sun_path, path, sizeof(server_addr.sun_path) - 1);
    
    int res;
    do {
        res = 0;
        if (connect(fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_un)) < 0) res = -errno;
    } 
    while (res == -EINTR);        
    
    if (res < 0) {
        close(fd);
        return;
    }

    sysvshm_server_fd = fd;    
}

static void sysvshm_close() {
    if (sysvshm_server_fd >= 0) {
        close(sysvshm_server_fd);
        sysvshm_server_fd = -1;
    }
}

static int sysvshm_shmget_request(size_t size) {
    if (sysvshm_server_fd < 0) return 0;
    
    char request_data[MIN_REQUEST_LENGTH];
    request_data[0] = REQUEST_CODE_SHMGET;
    memcpy(request_data + 1, &size, 4);
    
    int res = write(sysvshm_server_fd, request_data, sizeof(request_data));
    if (res < 0) return 0;
    
    int shmid;
    res = read(sysvshm_server_fd, &shmid, 4);
    return res == 4 ? shmid : 0;
}

static int sysvshm_get_fd_request(int shmid) {
    if (sysvshm_server_fd < 0) return 0;
    
    char request_data[MIN_REQUEST_LENGTH];
    request_data[0] = REQUEST_CODE_GET_FD;
    memcpy(request_data + 1, &shmid, 4);
    
    int res = write(sysvshm_server_fd, request_data, sizeof(request_data));
    if (res < 0) return -1;
    
    char zero = 0;
    struct iovec iovmsg = {.iov_base = &zero, .iov_len = 1};
    struct {
        struct cmsghdr align;
        int fds[1];
    } ctrlmsg;

    struct msghdr msg = {
        .msg_name = NULL,
        .msg_namelen = 0,
        .msg_iov = &iovmsg,
        .msg_iovlen = 1,
        .msg_flags = 0,
        .msg_control = &ctrlmsg,
        .msg_controllen = sizeof(struct cmsghdr) + sizeof(int)
    };

    struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg);
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    cmsg->cmsg_len = msg.msg_controllen;
    ((int*)CMSG_DATA(cmsg))[0] = -1;

    recvmsg(sysvshm_server_fd, &msg, 0);
    return ((int*)CMSG_DATA(cmsg))[0];
}

static void sysvshm_delete_request(int shmid) {
    if (sysvshm_server_fd < 0) return;
    
    char request_data[MIN_REQUEST_LENGTH];
    request_data[0] = REQUEST_CODE_DELETE;
    memcpy(request_data + 1, &shmid, 4);
    
    write(sysvshm_server_fd, request_data, sizeof(request_data));
}

static void sysvshm_delete(int index) {
    sysvshm_connect();
    sysvshm_delete_request(shmemories[index].id);
    sysvshm_close();

    if (shmemories[index].fd >= 0) close(shmemories[index].fd);
    shmemory_count--;
    memmove(&shmemories[index], &shmemories[index+1], (shmemory_count - index) * sizeof(shmemory_t));
}

int shmget(key_t key, size_t size, int flags) {
    if (key != IPC_PRIVATE) return -1;
    
    pthread_mutex_lock(&mutex);
        
    sysvshm_connect();
    int shmid = sysvshm_shmget_request(size);
    if (sh
