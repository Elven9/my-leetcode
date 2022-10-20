package main

func main() {
}

func strStr(haystack string, needle string) int {
	// TLE Version ?
	// O(mn)
	limit := len(haystack) - len(needle) + 1

Checker:
	for i := 0; i < limit; i++ {
		for j := 0; j < len(needle); j++ {
			if haystack[i+j] != needle[j] {
				continue Checker
			}
		}
		return i
	}
	return -1
}
