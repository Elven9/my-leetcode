package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(isPalindrome("A man, a plan, a canal: Panama"))
	fmt.Println(isPalindrome("race a car"))
	fmt.Println(isPalindrome(" "))
}

func isPalindrome(s string) bool {
	s = strings.ToLower(s)
	start, end := 0, 0
	newStr := make([]rune, len(s))

	for _, r := range s {
		// Remove non-alphanumeric character
		if !(r >= '0' && r <= '9') && !(r >= 'a' && r <= 'z') {
			continue
		}
		newStr[end] = r
		end++
	}

	// Check If is palimdrone
	if end%2 == 0 {
		start = end/2 - 1
	} else {
		start = end / 2
	}
	end /= 2

	for start >= 0 {
		if newStr[start] != newStr[end] {
			return false
		}
		start--
		end++
	}
	return true
}
