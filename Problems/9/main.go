package main

import "strconv"

func main() {}

func isPalindrome(x int) bool {
	// Convert to String and Palimdrone Check
	target := strconv.Itoa(x)
	start, end := 0, len(target)-1

	for start < end {
		if target[start] != target[end] {
			return false
		}
		start++
		end--
	}
	return true
}
