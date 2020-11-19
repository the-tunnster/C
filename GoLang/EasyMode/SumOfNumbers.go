package main

import "fmt"

func sumOfNumbers(){
	var number int
	fmt.Println("Enter a number, greater than zero, to calcualte the sum of numbers upto it.")
	fmt.Scanf("%d", &number)
	var sum int = 0
	if(number<0){
		fmt.Println("The number you've entered is less than zero.")
	}else{
		for i:=0;i<number;i++ {
			sum+=i
		}
	}		
	fmt.Printf("The num of numbers upto %d is %d.\n", number, sum)
}

func sumOfThreesAndFives(){
	var number int
	fmt.Println("Enter a number, greater than zero, to calcualte the sum of numbers upto it.")
	fmt.Scanf("%d", &number)
	var sum int = 0
	if(number<0){
		fmt.Println("The number you've entered is less than zero.")
	}else{
		for i:=0;i<number;i++ {
			if(i%3==0||i%5==0){
				sum+=i
			}
		}
	}		
	fmt.Printf("The num of numbers upto %d, that are multiples of 3 and/or 5, is %d.\n", number, sum)
}