package main

import "strings"

func main() {}

func customSortString(order string, s string) string {
	// Scan frequency and check order
	// Time Complexity: O(n), Space Complexity: O(1), if charset is << n
	freq := make(map[rune]int)
	for _, r := range s {
		freq[r]++
	}

	// Construct
	sb := strings.Builder{}

	for _, r := range order {
		sb.WriteString(strings.Repeat(string(r), freq[r]))
		delete(freq, r)
	}

	for k, v := range freq {
		sb.WriteString(strings.Repeat(string(k), v))
	}

	return sb.String()
}
