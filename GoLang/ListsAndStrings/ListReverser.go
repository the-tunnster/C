package listsandstrings

import "fmt"

func listReverser(){
	fmt.Println("How many elements are you going to enter?")
	var size int
	fmt.Scanf("%d", &size)
	var slice = make([]int, size)
	fmt.Println("Enter the elements :")
	for i:=0; i<size; i++{
		fmt.Scanf("%d", &slice[i])
	}
	for i:=0; i<size/2; i++{
		var temp = slice[i]
		slice[i] = slice[size-i-1]
		slice[size-i-1] = temp
	}
	fmt.Println("The reversed array is :")
	for i:=0; i<size; i++{
		fmt.Printf("%d\t", slice[i])
	}
	fmt.Println()
}