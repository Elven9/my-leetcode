package main

import "slices"

func main() {}

func maxSumAfterPartitioning(arr []int, k int) int {
	// Naive Solution, Partiton all Possibile Solution
	//
	// DP to the rescue, add or not to add. Found by thinking about merge sort.
	// Time Complexity: O(nk), Space Complexity: O(n)
	res := make([]int, len(arr)+1)
	m := len(arr)

	res[m] = 0
	res[m-1] = arr[m-1]

	for i := m - 2; i >= 0; i-- {
		best := 0
		maxInK := -1
		j := i
		for _k := 0; _k < k; _k++ {
			j++
			if j > m {
				break
			}
			if arr[j-1] > maxInK {
				maxInK = arr[j-1]
			}
			tmp := maxInK*(_k+1) + res[j]
			if tmp > best {
				best = tmp
			}
		}
		res[i] = best
	}

	return res[0]
}

func maxSumAfterPartitioningReadableVersion(arr []int, k int) int {
	// Naive Solution, Partiton all Possibile Solution
	//
	// DP to the rescue, add or not to add. Found by thinking about merge sort.
	// Time Complexity: O(nk), Space Complexity: O(n)
	res := make([]int, len(arr)+1)
	m := len(arr)

	getMaxSum := func(arr []int) int {
		return slices.Max(arr) * len(arr)
	}
	res[m] = 0
	res[m-1] = arr[m-1]

	for i := m - 2; i >= 0; i-- {
		best := 0
		for j := 1; j <= k && i+j <= m; j++ {
			tmp := getMaxSum(arr[i:i+j]) + res[i+j]
			if tmp > best {
				best = tmp
			}
		}
		res[i] = best
	}

	return res[0]
}
