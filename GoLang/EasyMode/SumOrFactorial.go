package main

import "fmt"

func sumOrFactorial(){
	var number int
	fmt.Println("Enter a number, greater than zero.")
	fmt.Scanf("%d", &number)
	fmt.Println("Would you like to calculate the sum of numbers upto it, or product of numbers upto it?")
	fmt.Println("Enter '1' for Summation or '2' for Factorial.")
	var choice int
	fmt.Scanf("%d", &choice)
	var result int 
	switch{
		case choice==1:
			result = 0
			for i:=0;i<number;i++ {
				result+=i
			}
		case choice==2:
			result = 1
			for i:=1;i<number;i++ {
				result*=i
			}
		default:
			fmt.Println("An invalid input was recieved.")
	}
	fmt.Printf("The resultant value is : %d.\n", result)
}