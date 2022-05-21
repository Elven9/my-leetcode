package main

import (
	"container/list"
	"fmt"
)

func main() {
	fmt.Println(isValid("]"))
}

func isValid(s string) bool {
	pairStack := list.New()

	for _, r := range s {
		switch r {
		case ')':
			if pairStack.Len() == 0 || pairStack.Remove(pairStack.Back()) != '(' {
				return false
			}
		case '}':
			if pairStack.Len() == 0 || pairStack.Remove(pairStack.Back()) != '{' {
				return false
			}
		case ']':
			if pairStack.Len() == 0 || pairStack.Remove(pairStack.Back()) != '[' {
				return false
			}
		default:
			pairStack.PushBack(r)
		}
	}

	return pairStack.Len() == 0
}
