package main

func main() {}

func canConstruct(ransomNote string, magazine string) bool {
	// Naive solution: scan magazine to construct viable charset, and check ransomNote
	//
	// Time Complexity: O(n+m), Space Complexity: O(1), if support charset is small
	charSet := make(map[rune]int)

	for _, r := range magazine {
		charSet[r]++
	}

	for _, r := range ransomNote {
		if charSet[r] == 0 {
			return false
		}
		charSet[r]--
	}
	return true
}
