package listsandstrings

import "fmt"

func largestElementFinder(){
	fmt.Println("How many elements do you wish to enter?")
	var size int
	var maxIndex int
	var maxValue int = -1
	numOfBytes, err := fmt.Scan(&size)
	if numOfBytes <=0 || err != nil{
		fmt.Println("Error encountered.")
	}else{
		var slice = make([]int, size)
		fmt.Println("Enter the values :")
		for i:=0; i<size; i++{
			fmt.Scanf("%d", &slice[i])
			if slice[i]>maxValue{						//Finds largest element at time of entry
				maxValue = slice[i]						//You could make a seperate function, but extra computing
				maxIndex = i
			}
		}
		fmt.Println("The lagrest element entered is :")
		fmt.Println(slice[maxIndex])
	}
	
}