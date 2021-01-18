package main

import "fmt"
import "strings"
import "unicode"

func findSpecificSum(){
	sequence := []string {"1", "", "2", "", "3", "", "4", "", "5", "", "6", "", "7", "", "8", "", "9"}
	arr := []string {"+", "-", ""}	
	for a:=0;a<3;a++{
		for b:=0;b<3;b++{
			for c:=0;c<3;c++{
				for d:=0;d<3;d++{
					for e:=0;e<3;e++{
						for f:=0;f<3;f++{
							for g:=0;g<3;g++{
								for h:=0;h<3;h++{
								sequence[1] =arr[a]
								sequence[3] =arr[b]
								sequence[5] =arr[c]	
								sequence[7] =arr[d]
								sequence[9] =arr[e]
								sequence[11] =arr[f]
								sequence[13] =arr[g]
								sequence[15] =arr[h]
								tempString := strings.Join(sequence, "")
								var sum int = performOperation(tempString)
								if(sum==100){
									fmt.Println(tempString)
								}
								}
							}
						}
					}
				}
			}
		}
	}
}

func performOperation(s string) int{
	var sum int = 0
	var currentNumber int = 0
	var count int = 0
	var currentOperator string = "+"
	
	for _, temp := range s{
		if(unicode.IsDigit(temp)){
			var x int = int(temp)
			x -= 48
			currentNumber = currentNumber*10 + x
			count++
		}else{
			nextOperator := string(temp)
			if(currentOperator=="+"){
				sum += currentNumber
			}
			if(currentOperator=="-"){
				sum -= currentNumber
			}
			count = 0
			currentNumber = 0
			currentOperator = nextOperator 
		}
	}
	if(currentOperator=="+"){
		sum += currentNumber
	}
	if(currentOperator=="-"){
		sum -= currentNumber
	}

	return (sum)
}