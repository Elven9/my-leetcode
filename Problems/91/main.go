package main

import (
	"fmt"
	"strconv"
)

func main() {
	numDecodings := numDecodings

	fmt.Println(numDecodings("12"))
	fmt.Println(numDecodings("226"))
	fmt.Println(numDecodings("06"))
	fmt.Println(numDecodings("27"))
}

func numDecodings(s string) int {
	// DP solution
	// O(n)
	// O(n)
	table := make([]int, len(s)+1)
	// 1
	table[len(s)] = 1
	table[len(s)-1] = 1
	if s[len(s)-1] == '0' {
		table[len(s)-1] = 0
	}

	for i := len(s) - 2; i >= 0; i-- {
		if s[i] == '0' {
			table[i] = 0
			continue
		}

		table[i] = table[i+1]
		if v, _ := strconv.Atoi(s[i : i+2]); v < 27 {
			table[i] += table[i+2]
		}
	}

	return table[0]
}

func numDecodings_recu(s string) int {
	// Recursive, TLE
	if len(s) == 0 {
		return 1
	}
	if s[0] == '0' {
		return 0
	}
	if len(s) == 1 {
		return 1
	}

	digit := int(s[0] - '0')
	if digit > 2 {
		return numDecodings_recu(s[1:])
	} else {
		result := numDecodings_recu(s[1:])
		if v, _ := strconv.Atoi(s[:2]); v < 27 {
			result += numDecodings_recu(s[2:])
		}
		return result
	}
}
