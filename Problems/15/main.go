package main

import (
	"fmt"
	"sort"
)

func main() {
	for _, res := range threeSum_Fully([]int{-1, 0, 1, 2, -1, -4}) {
		fmt.Println(res)
	}
}

func threeSum_Fully(nums []int) [][]int {
	sort.Ints(nums)
	res := make([][]int, 0)

	for i := 0; i < len(nums); {
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		for j, k := i+1, len(nums)-1; j < k; {
			n := nums[i] + nums[j] + nums[k]
			if n > 0 {
				k--
			} else if n < 0 {
				j++
			} else { // n == 0
				res = append(res, []int{nums[i], nums[j], nums[k]})
				for x := j; j < k && nums[x] == nums[j]; {
					j++
				}
			}
		}
		for i+1 < len(nums) && nums[i] == nums[i+1] {
			i++
		}
		i++
	}
	return res
}

func threeSum(nums []int) [][]int {
	// Naive Solution: O(n^3)
	// If the list contains zero, partial solutions can be obtained by using 2 sum
	// algorithm.
	//
	// Select one number, and donwgrade to 2sum?
	// Time Complexity: O(n^2)
	//
	// Problem are the duplicate ones.
	//
	// Delete the one that has been fully search.

	// Duplicate Issue
	sort.Ints(nums)
	res := make([][]int, 0)

	for i := 0; i < len(nums)-2; i++ {
		res = append(res, twoSum(nums[i+1:], -nums[i])...)
		for i+1 < len(nums) && nums[i+1] == nums[i] {
			i++
		}
	}

	return res
}

func twoSum(nums []int, target int) [][]int {
	// Assume One Solution
	// Hashmap Lookup, O(1)
	// linear scan, O(n)

	res := make([][]int, 0)

	// Remain -> Index
	remainBucket := make(map[int]struct{})

	for i := 0; i < len(nums); i++ {
		remain := target - nums[i]
		if _, ok := remainBucket[remain]; ok {
			res = append(res, []int{-target, nums[i], remain})
			for i+1 < len(nums) && nums[i+1] == nums[i] {
				i++
			}
		} else {
			remainBucket[nums[i]] = struct{}{}
		}
	}
	return res
}
