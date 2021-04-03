package main

import "fmt"
import "net/http"

func basicWebServer(){
	http.HandleFunc("/", index_handler)
	http.HandleFunc("/about", about_handler)

	http.ListenAndServe(":8080", nil)
}

func index_handler(w http.ResponseWriter, r *http.Request){
	fmt.Fprintf(w, "Hello, Index Here.")
}

func about_handler(w http.ResponseWriter, r *http.Request){
	fmt.Fprintf(w, "Hello, About Here.")
}