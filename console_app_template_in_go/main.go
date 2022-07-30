package main

import (
	"bufio"
	"fmt"
	"os"
	"os/signal"
	"strings"
)

func main() {
	setupSignalHandling()

	reader := bufio.NewReader(os.Stdin)
	for {
		userInput := promptForInput(reader)

		serializedInput := serializeUserInput(userInput)
		decideOutput(serializedInput)
	}
}

func setupSignalHandling() {
	c := make(chan os.Signal, 1)
	signal.Ignore(os.Interrupt)
	signal.Notify(c, os.Interrupt)

	go handleSignals(c)
}

func handleSignals(c <-chan os.Signal) {
	s := <-c

	fmt.Println("\nGot signal:", s)
	fmt.Println(
		"Type \"exit\" to quit the program or \"help\" to see" +
			" the list of all available commands.")
	fmt.Println()

	go handleSignals(c)
}

func promptForInput(reader *bufio.Reader) string {
	fmt.Print(">>> ")

	userInput, _ := reader.ReadString('\n')
	//if err != nil {
	//	return "", fmt.Errorf("%w", err)
	//}

	return userInput
}

func serializeUserInput(userInput string) []string {
	userInput = strings.ToLower(userInput)
	userInput = strings.Replace(userInput, "\r", "", -1)
	userInput = strings.Replace(userInput, "\n", "", -1)

	return strings.Fields(userInput)
}

func decideOutput(userInput []string) {
	switch {
	case len(userInput) == 0:
		fmt.Println()
	case userInput[0] == "help":
		printHelp()
	case userInput[0] == "hello":
		printHello()
	case userInput[0] == "exit":
		os.Exit(0)
	default:
		printUnknownCommand()
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

func printHello() {
	fmt.Println("Greetings, User!")
	fmt.Println()
}

func printUnknownCommand() {
	fmt.Println("I don't know that command, try using \"help\".")
	fmt.Println()
}
