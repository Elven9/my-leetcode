package main

import "sort"

func main() {}

func divideArray(nums []int, k int) [][]int {
	// Naive Solution: Using sort to sort all nums. Since len(nums) %3 == 0,
	// every element in nums should be used at least once if the answer existed.
	// Time complexity: O(nlogn), space complexity: O(1)

	sort.Ints(nums)

	res := make([][]int, 0, len(nums)/3)
	// Check if is valid
	for i := 1; i < len(nums); i += 3 {
		if nums[i]-nums[i-1] <= k && nums[i+1]-nums[i] <= k && nums[i+1]-nums[i-1] <= k {
			res = append(res, []int{nums[i-1], nums[i], nums[i+1]})
		} else {
			return [][]int{}
		}
	}
	return res
}
