package main

import "C"

func main() {}

func dailyTemperatures(temperatures []int) []int {
	res := make([]int, len(temperatures))
	stack, sp := make([]int, len(temperatures)), -1

	for i, temp := range temperatures {

		for sp != -1 {
			tmp := stack[sp]
			if temperatures[tmp] < temp {
				res[tmp] = i - tmp
				sp--
				continue
			}
			break
		}
		sp++
		stack[sp] = i
	}

	return res
}
