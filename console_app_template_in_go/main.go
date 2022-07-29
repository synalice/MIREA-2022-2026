package main

import (
	"bufio"
	"fmt"
	"os"
	"os/signal"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	c := make(chan os.Signal, 1)
	signal.Ignore()
	signal.Notify(c, os.Interrupt)

	for {
		fmt.Print(">>> ")

		go signalHandler(c)

		userInput, _ := reader.ReadString('\n')

		if userInput == "" {
			// Handling ctrl+d (EOF)
			fmt.Println("\nGot signal: Ctrl+D")
			fmt.Println(
				"Type \"exit\" to quit the program or \"help\" to see" +
					"the list of all available commands\"")
			fmt.Println()
			continue
		}

		userInput = strings.ToLower(userInput)
		userInput = strings.Replace(userInput, "\r", "", -1)
		userInput = strings.Replace(userInput, "\n", "", -1)
		parsedInput := strings.Fields(userInput)

		switch {
		case len(parsedInput) == 0:
			fmt.Println()
		case parsedInput[0] == "help":
			printHelp()
		case parsedInput[0] == "hello":
			fmt.Println("Greetings, User!")
			fmt.Println()
		case parsedInput[0] == "exit":
			os.Exit(0)
		default:
			fmt.Println("I don't know that command, try using \"help\".")
		}
	}
}

func printHelp() {
	fmt.Println("Here is the list of things I can do:")
	fmt.Println("====================================")
	fmt.Println("help        Prints help")
	fmt.Println("hello       Says hello")
	fmt.Println("exit        Exits the application")
	fmt.Println()
}

func signalHandler(c <-chan os.Signal) {
	s := <-c
	fmt.Println("\nGot signal:", s)
	fmt.Println(
		"Type \"exit\" to quit the program or \"help\" to see" +
			"the list of all available commands\"")
	fmt.Print("\n>>> ")
	go signalHandler(c)
}
