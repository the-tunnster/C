package main

import "fmt"
import "os"
import "bufio"
import "strings"
import "strconv"
import "encoding/json"



func main(){
	name := newSentenceReader()
	fmt.Println(name)
}

func helloWorld(){
	fmt.Println("Hello World!")
}

func nameAskerPrinter(){
	fmt.Println("Please enter your name.")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Println("Hello ", scanner.Text())
}

func sumPrinter(){
	fmt.Println("Enter a number.")
	var num int
	fmt.Scanf("%d", &num)
	var sum int = 0
	for i := 0; i <= num; i++{
		sum += i
	}
	fmt.Printf("The sum of numbers upto %d is : %d.", num, sum)
}

func productPrinter(){
	fmt.Println("Enter a number.")
	var num int
	fmt.Scanf("%d", &num)
	var prod int = 1
	for i := 1; i <= num; i++{
		prod = prod * i
	}
	fmt.Printf("The product of numbers upto %d is : %d.", num, prod)
}

func primeChecker(x int) bool{
	var flag bool = true
	for i := 2; i < x; i++{
		if x%i != 0{
			continue
		}
		flag = false
		break
	}
	return flag
}

func allPrime(){
	fmt.Println("Enter a number.")
	var num int
	fmt.Scanf("%d", &num)
	fmt.Println("Prime numbers upto that number are :")
	for i := 2; i <= num; i++{
		if primeChecker(i){
			fmt.Printf("%d\t", i)
		}
	}
	fmt.Println()
}

func guessWork(){
	fmt.Printf("Here's how this goes.\nI have a predefined number.\nYou have to guess what it is.\n")
	fmt.Printf("You will be given a hint as to whether you're higher or lower, or be told your guess was correct.\nYou may begin.\n")
	const value = 69
	const limit = 20
	var guess int
	var count int = 0
	for ;;{
		fmt.Scanf("%d", &guess)
		if guess == value{
			fmt.Printf("Your guess was correct.\n")
			break
		}
		if guess < value{
			fmt.Printf("Your guess is lower than the correct value.\n")
		}
		if guess > value{
			fmt.Printf("Your guess is higher than the correct value.\n")
		}
		count ++
		if count == limit{
			fmt.Printf("You're kinda bad at this lmao.\nWe're ending this now.\n")
			break
		}
	}
}

func largestFinder(){
	fmt.Println("How many elements do you want to enter?")
	var n int
	fmt.Scanf("%d", &n)
	arr := make([]int, n)
	fmt.Printf("Enter the %d elements.\n", n)
	var max int = -1
	for i := 0; i<n; i++{
		fmt.Scanf("%d", &arr[i])
		if arr[i]>max{
			max = arr[i]
		}
	}
	fmt.Printf("The largest element is %d.\n", max)
}

func arrayReverser(){
	fmt.Println("How many elements do you want to enter?")
	var n int
	fmt.Scanf("%d", &n)
	arr := make([]int, n)
	fmt.Printf("Enter the %d elements.\n", n)
	for i := 0; i<n; i++{
		fmt.Scanf("%d", &arr[i])
	}
	for i:=0; i<n/2; i++{
		temp := arr[i]
		arr[i] = arr[n-i-1]
		arr[n-i-1] = temp
	}
	fmt.Println("The reversed array is :")
	for i := 0; i<n; i++{
		fmt.Printf("%d\t", arr[i])
	}
}

func elementFinder(){
	fmt.Println("How many elements do you want to enter?")
	var n int
	fmt.Scanf("%d", &n)
	arr := make([]int, n)
	fmt.Printf("Enter the %d elements.\n", n)
	for i := 0; i<n; i++{
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Println("Which element do you wish to find?")
	var value int
	var position int = -1
	fmt.Scanf("%d", &value)
	for i:=1; i<n; i++{
		if arr[i]==value{
			position = i+1
			break
		}
	}
	if position != -1{
		fmt.Printf("Value found at position %d.\n", position)
	}
	if position == -1{
		fmt.Println("Value not found.")
	}
}

func arrayTotaler(){
	fmt.Println("How many elements do you want to enter?")
	var n int
	fmt.Scanf("%d", &n)
	arr := make([]int, n)
	var sum int = 0
	fmt.Printf("Enter the %d elements.\n", n)
	for i := 0; i<n; i++{
		fmt.Scanf("%d", &arr[i])
		sum += arr[i]
	}
	fmt.Printf("The sum of the elemments is %d.\n", sum)
}

func sentenceReader() string{
	inputReader := bufio.NewReader(os.Stdin)
	input, _ := inputReader.ReadString('\n')
	fixed := strings.Replace(input, "\n", "", -1)
    	return fixed
}

func newSentenceReader() string{
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Enter your name please.")
	var name string
	scanner.Scan()
	name = scanner.Text()
	return name
}

func truncator(){
	fmt.Println("Enter a floating point number please.")
	var fltpt float64
	var rounded int64
	fmt.Scanf("%f", &fltpt)
	rounded = int64(fltpt)
	fmt.Printf("The truncated value is %d.\n", rounded)
}

func findIAN(){
	fmt.Println("Enter a string.")
	var str string
	fmt.Scanf("%s", &str)
	var test bool = false
	if strings.Contains(str, "a")||strings.Contains(str, "A"){
		if strings.HasPrefix(str, "i")||strings.HasPrefix(str, "I"){
			if strings.HasSuffix(str, "n")||strings.HasSuffix(str, "N"){
				test = true
			}

		}
	}
	if test{
		fmt.Println("Found!")
	}else{
		fmt.Println("Not Found!")
	}
}

func sliceAppender(){
	arr := make([]int, 3, 100)
	var num int
	fmt.Println("How many numbers do you wish to enter?")
	fmt.Scanf("%d", &num)
	fmt.Printf("Enter %d values.\n", num)
	for i := 0;i < num; i++{
		var input string
		fmt.Scanf("%s", &input)
		if input == "X" || input == "x"{
			fmt.Println("Exiting")
			break
		}else{
			if i <= 2{
				arr[i], _ = strconv.Atoi(input)
			}else{
				temp, _ := strconv.Atoi(input)
				arr = append(arr, temp)
			}
		}	
	}
	fmt.Println(arr)
}

func mapsAndJsons(){
	inputReader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a name please.")
	temp, _ := inputReader.ReadString('\n')
	name := strings.Replace(temp, "\n", "", -1)
	fmt.Println("Enter an address.")
	temp2, _ := inputReader.ReadString('\n')
	address := strings.Replace(temp2, "\n", "", -1)
	var mapper map[string]string
	mapper = make(map[string]string)
	fmt.Printf("Name entered : %s.\n", name)
	fmt.Printf("Address entered : %s.\n", address)
	mapper[name]=address
	jsonForm, _ := json.Marshal(mapper)
	fmt.Println(jsonForm)
}

func fileReading(){

	type fullName struct{
		fname, lname string
	}

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Please enter the name of the text file.")
	scanner.Scan()
	fileName := scanner.Text()
	var f *os.File
	nameArr := make([]fullName, 0, 1)
	for{
		fi, err := os.Open(fileName)
		if err != nil {
			fmt.Printf("ERROR: %v\n", err)
			fmt.Println("Please Enter valid file name:")
			scanner.Scan()
			fileName = scanner.Text()
		}else{
			f = fi
			break
		}
	}
	fScanner := bufio.NewScanner(f)
	var arr []string
	for fScanner.Scan() {
		arr = strings.Split(fScanner.Text(), " ")
		nameArr = append(nameArr, fullName{arr[0], arr[1]})
	}
	f.Close()
	for _, name := range nameArr {
		fmt.Printf("%v - %v\n", name.fname, name.lname)
	}
}