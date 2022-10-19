package main

import "strconv"

func main() {

}

func evalRPN(tokens []string) int {
	stack := make([]int, 10000)
	sp := -1

	for _, token := range tokens {
		switch token {
		case "+":
			stack[sp-1] = stack[sp-1] + stack[sp]
			sp--
		case "-":
			stack[sp-1] = stack[sp-1] - stack[sp]
			sp--
		case "*":
			stack[sp-1] = stack[sp-1] * stack[sp]
			sp--
		case "/":
			stack[sp-1] = stack[sp-1] / stack[sp]
			sp--
		default:
			sp++
			stack[sp], _ = strconv.Atoi(token)
		}
	}
	return stack[0]
}
