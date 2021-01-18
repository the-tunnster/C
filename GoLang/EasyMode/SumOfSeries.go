package easymode

import "fmt"
import "math"

func sumOfSeries(){
	var sum float64 = 0
	for i:=1;i<=1000000;i++{
		sum += math.Pow(-1, float64(i+1))/(2*(float64(i+1)))
	}
	fmt.Printf("The sum of the series is %f.\n", sum)
}