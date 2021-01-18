package easymode

import "fmt"

func next20LeapYears(){
	var currentYear int
	fmt.Println("Enter the current year.")
	fmt.Scanf("%d", &currentYear)
	var count int = 0
	for count<20{
		currentYear++
		if currentYear%4==0{
			if currentYear%100==0&&currentYear%400==0{
					fmt.Printf("%d is a leap year.\n", currentYear)
					count++
			}else if currentYear%100==0&&currentYear%400!=0{
				continue
			}
			fmt.Printf("%d is a leap year.\n", currentYear)
			count++
		}
	}
}