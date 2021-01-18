package easymode

import "fmt"
import "bufio"
import "os"
import "strings"

func namePrint(){
	reader := bufio.NewReader(os.Stdin)
	var name string
	fmt.Println("Enter your name please.")
	name, _ = reader.ReadString('\n')
	name = strings.Replace(name, "\n", "", -1)
	fmt.Printf("The name entered was %s.\n", name)
}

func specificNamePrint(){
	reader := bufio.NewReader(os.Stdin)
	var name string
	var testName string = "Alice"
	fmt.Println("Enter your name please.")
	name, _ = reader.ReadString('\n')
	if(name==testName){
		fmt.Printf("How's it going, %s?\n", name)
	}else{
		fmt.Println("Hello.")
	}
}