package main

import "fmt"

func main() {
	fmt.Println(isAnagram("a", "ab"))
}

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	requ := make(map[rune]int)
	for _, r := range s {
		requ[r]++
	}

	// Check
	for _, r := range t {
		requ[r]--
		if requ[r] < 0 {
			return false
		}
	}
	return true
}
