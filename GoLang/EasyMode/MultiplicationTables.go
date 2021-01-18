package easymode

import "fmt"

func tablePrinter(){
	for i:=1;i<=12;i++{
		for j:=1;j<=10;j++{
			fmt.Printf("%d times %d is %d.\n", i, j, (i*j))
		}
	fmt.Println("******************")
	}
}