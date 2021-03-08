package main

import "fmt"

func elementLocator(){
	fmt.Println("How many elements are you going to enter?")
	var size int
	fmt.Scanf("%d", &size)
	var slice = make([]int, size)
	fmt.Println("Enter the elements :")
	for i:= 0; i<size; i++{
		fmt.Scanf("%d", &slice[i])
	}
	var check int
	var flag int
	fmt.Println("Enter the element you wish to search for.")
	fmt.Scanf("%d", &check)
	for i :=0 ; i < size ; i++{
		if(slice[i]==check){
			flag = i
		}
	}
	if(flag==0){
		fmt.Println("The element wasn't present in the list.")
	}else{
		fmt.Println("The element was located at index", flag)
	}
}