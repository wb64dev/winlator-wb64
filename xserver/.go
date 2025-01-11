API Server
```
package main

import (
    "encoding/json"
    "net/http"
)

type Message struct {
    Message string `json:"xserver"`
}

func handleMessage(w http.ResponseWriter, r *http.Request) {
    msg := Message{Message: "updating"}
    json.NewEncoder(w).Encode(msg)
}

func main() {
    http.HandleFunc("/", handleMessage)
    http.ListenAndServe(":8080", nil)
}
```
