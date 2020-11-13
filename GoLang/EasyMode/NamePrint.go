package main

import "fmt"

func namePrint(){
	var firstName string
	var lastName string
	fmt.Println("Enter your name please.")
	fmt.Scanf("%s%s", &firstName, &lastName)
	fmt.Printf("The name entered was %s %s.\n", firstName, lastName)
}

func specificNamePrint(){
	var firstName string
	var testName string = "Alice"
	fmt.Println("Please enter your firstname.")
	fmt.Scanf("%s", &firstName)
	if(firstName==testName){
		fmt.Printf("How's it going, %s?\n", firstName)
	}else{
		fmt.Println("Hello.")
	}
}