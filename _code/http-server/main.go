package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", rootHandler)

	http.ListenAndServe(":8080", nil)
}

func rootHandler(w http.ResponseWriter, req *http.Request) {
	fmt.Fprint(w, "hello there")
}
