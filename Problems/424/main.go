package main

import "fmt"

func main() {
	fmt.Println(characterReplacement("ABAB", 2))
	fmt.Println(characterReplacement("AABABBA", 1))
	fmt.Println(characterReplacement("AAAA", 2))
	fmt.Println(characterReplacement("AABA", 0))
	fmt.Println(characterReplacement("SDSSMESSTR", 2))
	fmt.Println(characterReplacement("ABBB", 2))
}

func characterReplacement(s string, k int) int {
	// Sliding Windows Solution
	// O(n)
	// Space: O(1)
	result := 0
	cCount := make([]int, 26)
	start, maxCount := 0, 0

	for end, c := range s {
		cCount[c-'A']++
		if cCount[c-'A'] > maxCount {
			maxCount = cCount[c-'A']
		}

		if end-start+1-maxCount > k {
			cCount[s[start]-'A']--
			start++
		}

		if end-start+1 > result {
			result = end - start + 1
		}
	}

	return result
}

func characterReplacement_On2(s string, k int) int {
	// O(n^2)
	// Space: O(1)
	result := 0
	for i, r := range s {
		remain, cnt := k, 0
		for i+cnt < len(s) && (remain > 0 || s[i+cnt] == byte(r)) {
			if s[i+cnt] != byte(r) {
				remain--
			}
			cnt++
		}
		tmp := cnt + remain
		if i < remain {
			tmp = cnt + i
		}
		if tmp > result {
			result = tmp
		}
	}

	return result
}
