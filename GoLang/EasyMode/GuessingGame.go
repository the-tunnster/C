package easymode

import "fmt"

func numberGuesser(){
	var nice int = 69
	var blazeIt int = 420
	var lameNumber = 50
	fmt.Println("Enter a number, and I'll tell you if you got it right, or if your guess was too high or too low.")
	var currentGuess int = -1
	var previousGuess int = 0
	var guessed bool = false
	var count int = 0
	for guessed!=true{
		fmt.Print("Enter your guess : ")
		fmt.Scanf("%d", &currentGuess)
		count++
		if(currentGuess==lameNumber){
			guessed=true
			break
		}
		if(currentGuess==previousGuess){
			count--
			fmt.Println("You entered the same number twice.")
			continue
		}
		if(currentGuess==nice){
			count--
			fmt.Println("Nice, That's on me. Try again.")
			continue
		}
		if(currentGuess==blazeIt){
			count--
			fmt.Println("Blaze it fam, That's on me. Try again.")
			continue
		}
		switch{
			case currentGuess<lameNumber :
				previousGuess = currentGuess
				fmt.Println("Your guess was too low.")

			case currentGuess>lameNumber :
				previousGuess = currentGuess
				fmt.Println("Your guess was too high.")
		}
	}
	fmt.Printf("You got it right. Only took you %d tries.", count)
}