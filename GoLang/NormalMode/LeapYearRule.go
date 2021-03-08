package main

import (
	"fmt"
	"math"
)

func leapYearRuleMaker(){
	fmt.Println("Enter the number of days in the year, along with the fractional part.")
	var numOfDays float64
	fmt.Scanf("%f", &numOfDays)
	whole, fractional := math.Modf(numOfDays)
	fmt.Println("The regular number of days in a year will be ", whole,".")
	numShortYears := 1/fractional
	fmt.Println("You will need to add an extra day to a year, every ", numShortYears,"year/s.")
}