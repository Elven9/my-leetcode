package main

import "fmt"

func main() {
	fmt.Println(sortedSquares([]int{-7, -3, 2, 3, 11}))
}

func sortedSquares(nums []int) []int {
	neg, pos := 0, len(nums)-1
	res, idx := make([]int, len(nums)), len(nums)-1

	for idx >= 0 {
		if -nums[neg] >= nums[pos] {
			res[idx] = nums[neg] * nums[neg]
			neg++
		} else {
			res[idx] = nums[pos] * nums[pos]
			pos--
		}
		idx--
	}

	return res
}

func sortedSquares_cut(nums []int) []int {
	// Two pointer solution, O(n)
	neg, pos := 0, 1
	res := make([]int, 0, len(nums))

	// Get the cut point
	if nums[0] >= 0 {
		// All >= 0
		neg, pos = -1, 0
	} else if nums[len(nums)-1] < 0 {
		// All < 0
		neg, pos = len(nums)-1, len(nums)
	} else {
		for nums[neg] < 0 && nums[pos] < 0 {
			neg++
			pos++
		}
	}

	// Generate result
	for neg >= 0 && pos < len(nums) {
		if -nums[neg] <= nums[pos] {
			res = append(res, nums[neg]*nums[neg])
			neg--
		} else {
			res = append(res, nums[pos]*nums[pos])
			pos++
		}
	}
	for neg >= 0 {
		res = append(res, nums[neg]*nums[neg])
		neg--
	}
	for pos < len(nums) {
		res = append(res, nums[pos]*nums[pos])
		pos++
	}

	return res
}
