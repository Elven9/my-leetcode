package main

import "slices"

func main() {}

func hIndex(citations []int) int {
	// Simple solution will be O(mn) to scan each index with diff h and get the result
	// Max value + Binary Scan ? may be it can reduce to O(nlogn)

	st, ed := 0, slices.Max(citations)
	res := ed / 2

	// Custom binary search
	for st <= ed {
		tmp := 0

		for _, v := range citations {
			if v >= res {
				tmp++
			}
		}

		if tmp == res {
			break
		} else if tmp > res {
			st = res + 1
		} else {
			ed = res - 1
		}
		res = (ed + st) / 2
	}

	return res
}
