package main

import "fmt"

func main() {
	fmt.Println(countSubstrings("abc"))
	fmt.Println(countSubstrings("aaa"))
	fmt.Println(countSubstrings(""))
}

func countSubstrings(s string) int {
	// O(n^2) Solution
	// O(1) Space
	if len(s) == 0 {
		return 0
	}

	result := 1

	for i := 1; i < len(s); i++ {
		// a
		result++

		ts, te := 0, 0
		// aa
		if s[i] == s[i-1] {
			result++
			ts, te = i-1, i
			for {
				if ts-1 >= 0 && te+1 < len(s) && s[ts-1] == s[te+1] {
					ts--
					te++
					result++
				} else {
					break
				}
			}
		}

		// aba
		if i+1 < len(s) && s[i-1] == s[i+1] {
			result++
			ts, te = i-1, i+1
			for {
				if ts-1 >= 0 && te+1 < len(s) && s[ts-1] == s[te+1] {
					ts--
					te++
					result++
				} else {
					break
				}
			}
		}
	}

	return result
}
