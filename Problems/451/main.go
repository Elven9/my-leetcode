package main

import (
	"sort"
	"strings"
)

func main() {}

func frequencySort(s string) string {
	// Naive solution: scan to get frequency, sort character set, and construct string
	//
	// Time complexity: O(n), if n >> char set, Space complexity: O(1)
	freq := make(map[rune]int)

	// Scan string
	for _, r := range s {
		freq[r]++
	}

	// Get charset
	charset := make([]rune, 0)
	for k, _ := range freq {
		charset = append(charset, k)
	}

	// Sort chat set by freq
	sort.Slice(charset, func(i, j int) bool {
		ri, rj := charset[i], charset[j]
		if freq[ri] == freq[rj] {
			return ri < rj
		}
		return freq[ri] > freq[rj]
	})

	// Construct String
	res := make([]string, 0, len(charset))
	for _, r := range charset {
		res = append(res, strings.Repeat(string(r), freq[r]))
	}
	return strings.Join(res, "")
}
