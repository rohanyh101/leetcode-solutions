package main

import "fmt"

func isValid(s string) bool {
	stack := []int32{}

	for _, char := range s {
		switch char {
		case '(', '{', '[':
			stack = append(stack, char)
		case ')':
			if len(stack) == 0 || stack[len(stack)-1] != '(' {
				return false
			}
			stack = stack[:len(stack)-1]
		case '}':
			if len(stack) == 0 || stack[len(stack)-1] != '{' {
				return false
			}
			stack = stack[:len(stack)-1]
		case ']':
			if len(stack) == 0 || stack[len(stack)-1] != '[' {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}

	return len(stack) == 0
}

func main() {
	// Test cases
	tests := []string{
		"()",
		"()[]{}",
		"(]",
		"([)]",
		"{[]}",
	}

	for _, test := range tests {
		if isValid(test) {
			fmt.Printf("%q is valid\n", test)
		} else {
			fmt.Printf("%q is invalid\n", test)
		}
	}
}
