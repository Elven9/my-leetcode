package main

import "fmt"

func main() {
	fmt.Println(searchInsert([]int{1, 3, 5, 6}, 5))
}

func searchInsert(nums []int, target int) int {
	// Binary Search
	res := len(nums) / 2
	st, ed := 0, len(nums)

	for ed-st > 0 {
		if target < nums[res] {
			ed = res
		} else if target > nums[res] {
			st = res + 1
		} else {
			return res
		}
		res = (ed + st) / 2
	}
	return res
}
