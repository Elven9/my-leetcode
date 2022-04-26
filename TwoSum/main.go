package main

import (
	"fmt"
)

func main() {
	// Testcases
	// Nums, Target, Expected
	nums := [][]int{
		{2, 7, 11, 15},
		{3, 2, 4},
		{3, 3},
	}

	target := []int{
		9, 6, 6,
	}

	twoSum := twoSum_hashmap_scan

	for i := 0; i < len(nums); i++ {
		res := twoSum(nums[i], target[i])
		fmt.Println(res)
	}
}

func twoSum_double_loop(nums []int, target int) []int {
	// O(n^2)
	for ii, i := range nums {
		for ij, j := range nums {
			if ii == ij {
				continue
			}
			if i+j == target {
				return []int{ii, ij}
			}
		}
	}
	return []int{}
}

func twoSum_hashmap_scan(nums []int, target int) []int {
	// Assume One Solution
	// Hashmap Lookup, O(1)
	// linear scan, O(n)

	// Remain -> Index
	remainBucket := make(map[int]int)

	for idx, v := range nums {
		remain := target - v
		if i, ok := remainBucket[remain]; ok {
			return []int{i, idx}
		} else {
			remainBucket[v] = idx
		}
	}
	return []int{}
}
