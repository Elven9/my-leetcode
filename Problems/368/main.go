package main

import (
	"slices"
)

func main() {}

func largestDivisibleSubset(nums []int) []int {
	// DP solution + Backtracking ...
	// Since we only need to return one possible solution, we can use backtracking
	// to generate solution.
	bestIdx, bestLen := -1, -1
	maxSubsetLen := make([]int, len(nums))

	// First sort the nums => O(nlogn)
	// Two benefits ->
	// 1. no need to check a > b or b > a
	// 2. to check viable solution, we only need to check n % max number in candidate subarray == 0
	slices.Sort(nums)

	for i, n := range nums {
		tmp := 1
		for j := 0; j < i; j++ {
			if n%nums[j] == 0 && maxSubsetLen[j]+1 > tmp {
				tmp = maxSubsetLen[j] + 1
			}
		}
		maxSubsetLen[i] = tmp
		if tmp > bestLen {
			bestLen = tmp
			bestIdx = i
		}
	}

	// Reconstruct Subset
	res := make([]int, 0, bestLen)
	for {
		tmp := nums[bestIdx]
		res = append(res, tmp)
		bestLen--
		if bestLen == 0 {
			break
		}
		// Backtracking to reconstruct one possible solution
		for i := bestIdx; i >= 0; i-- {
			if maxSubsetLen[i] == bestLen && tmp%nums[i] == 0 {
				bestIdx = i
				break
			}
		}
	}

	return res
}

func largestDivisibleSubset_TLE(nums []int) []int {
	// Naive solution: check every combination (O(n!) time)
	// TLE Solution ...
	var best []int
	candidates := make([][]int, 0)

	check := func(n int, cand []int) bool {
		// assert: n > num in cand
		return n%cand[len(cand)-1] == 0
	}

	slices.Sort(nums)
	for _, n := range nums {
		// Check every candidate
		newCand := make([][]int, 0)
		for _, cand := range candidates {
			if check(n, cand) {
				tmp := append(slices.Clone(cand), n)
				newCand = append(newCand, tmp)
				if len(tmp) >= len(best) {
					best = tmp
				}
			}
		}
		candidates = append(candidates, []int{n})
		candidates = append(candidates, newCand...)
	}

	if len(best) == 0 {
		return []int{nums[0]}
	}
	return best
}
