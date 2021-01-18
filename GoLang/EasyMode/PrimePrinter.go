package main

import "fmt"

func primePrinter(){
	for i:=2;i<100;i++{									//Replace the conditional with whatever number you want
		var test bool = true							//i.e. "i<100"
		for j:=2;j<i;j++{
			if (i%j==0){
				test = false
				break
			}
		}
		if (test==true){
			fmt.Printf("%d is a prime number.\n", i)
		}
	}
}