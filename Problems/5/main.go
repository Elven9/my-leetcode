package main

import "fmt"

func main() {
	fmt.Println(longestPalindrome("babad") + "|")
	fmt.Println(longestPalindrome("cbbd") + "|")
	fmt.Println(longestPalindrome(" ") + "|")
	fmt.Println(longestPalindrome("") + "|")
}

func longestPalindrome(s string) string {
	// O(n^2) Solution
	// O(1) Space
	if len(s) == 0 {
		return ""
	}

	maxLen := 0
	mstart, mend := 0, 0

	for i := 1; i < len(s); i++ {
		ts, te := 0, 0
		// aa
		if s[i] == s[i-1] {
			ts, te = i-1, i
			for {
				if ts-1 >= 0 && te+1 < len(s) && s[ts-1] == s[te+1] {
					ts--
					te++
				} else {
					break
				}
			}
			if te-ts+1 > maxLen {
				maxLen = te - ts + 1
				mstart = ts
				mend = te
			}
		}

		// aba
		if i+1 < len(s) && s[i-1] == s[i+1] {
			ts, te = i-1, i+1
			for {
				if ts-1 >= 0 && te+1 < len(s) && s[ts-1] == s[te+1] {
					ts--
					te++
				} else {
					break
				}
			}
			if te-ts+1 > maxLen {
				maxLen = te - ts + 1
				mstart = ts
				mend = te
			}
		}
	}

	return s[mstart : mend+1]
}
