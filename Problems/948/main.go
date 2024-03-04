package main

import "sort"

func main() {}

func bagOfTokensScore(tokens []int, power int) int {
	// Naive solution: sort and scan to get the maxima score, O(nlogn), O(1)
	res := 0
	sort.Ints(tokens)

	start, end, cur := 0, len(tokens)-1, 0
	for start <= end {
		if power >= tokens[start] {
			power -= tokens[start]
			start++
			cur++
			if cur > res {
				res = cur
			}
		} else if cur > 0 {
			power += tokens[end]
			end--
			cur--
		} else {
			break
		}
	}

	return res
}
