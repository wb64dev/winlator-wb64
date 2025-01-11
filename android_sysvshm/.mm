int shmget(key_t key, size_t size, int flags) {
    if (key != IPC_PRIVATE) return -1;
    
    pthread_mutex_lock(&mutex);
        
    sysvshm_connect();
    int shmid = sysvshm_shmget_request(size);
    if (shmid == 0) {
        pthread_mutex_unlock(&mutex);
        return -1;
    }
    
    int fd = sysvshm_get_fd_request(shmid);
    if (fd == -1) {
        sysvshm_delete_request(shmid);
        pthread_mutex_unlock(&mutex);
        return -1;
    }
    
    void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        sysvshm_delete_request(shmid);
        close(fd);
        pthread_mutex_unlock(&mutex);
        return -1;
    }
    
    if (shmemory_count == 0) {
        shmemories = (shmemory_t*)malloc(sizeof(shmemory_t));
    } else {
        shmemories = (shmemory_t*)realloc(shmemories, (shmemory_count + 1) * sizeof(shmemory_t));
    }
    
    shmemories[shmemory_count].id = shmid;
    shmemories[shmemory_count].addr = addr;
    shmemories[shmemory_count].fd = fd;
    shmemories[shmemory_count].size = size;
    shmemories[shmemory_count].marked_for_delete = 0;
    
    shmemory_count++;
    
    pthread_mutex_unlock(&mutex);
    
    return shmid;
}

