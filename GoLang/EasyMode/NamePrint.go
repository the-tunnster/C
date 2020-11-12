package main

import "fmt"

func namePrint(){
	var firstName string
	var lastName string
	fmt.Println("Enter your name please.")
	fmt.Scanf("%s%s", &firstName, &lastName)
	fmt.Printf("The name entered was %s %s.\n", firstName, lastName)
}