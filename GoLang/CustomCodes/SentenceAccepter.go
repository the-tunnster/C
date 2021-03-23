package main

import "fmt"
import "os"
import "bufio"
import "strings"

func sentenceAccepter() string{
	var toReturn string
	bufferedReader := bufio.NewReader(os.Stdin)
	fmt.Println("Please enter a sentence.")
	sentence, err := bufferedReader.ReadString('\n')
	if(err!=nil){
		fmt.Println("There was an error in accepting the sentence.")
		toReturn = ""
	}else{
		toReturn = strings.Replace(sentence, "\n", "", -1)
	}
	return (toReturn)
}