package main

import "fmt"

func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
	fmt.Println(lengthOfLongestSubstring("aab"))
	fmt.Println(lengthOfLongestSubstring("abba"))
}

func lengthOfLongestSubstring(s string) int {
	// O(n)
	// Space O(C)

	result := 0
	charMap := make(map[rune]int)

	start := 0
	for i, r := range s {
		if prev, ok := charMap[r]; ok && prev >= start {
			if i-start > result {
				result = i - start
			}
			start = prev + 1
		}
		charMap[r] = i
	}

	// Last check
	if len(s)-start > result {
		result = len(s) - start
	}

	return result
}
