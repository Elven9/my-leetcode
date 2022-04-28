package main

import "fmt"

func main() {

	productExceptSelf := productExceptSelf

	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))
	fmt.Println(productExceptSelf([]int{-1, 1, 0, -3, 3}))
}

func productExceptSelf(nums []int) []int {
	// Scan Two Time, Both Direction
	// O(n), without using division operation
	// O(n) Space complexity
	fStart := make([]int, len(nums))
	fEnd := make([]int, len(nums))

	fStart[0] = nums[0]
	fEnd[0] = nums[len(nums)-1]

	for i := 1; i < len(nums); i++ {
		fStart[i] = fStart[i-1] * nums[i]
		fEnd[i] = fEnd[i-1] * nums[len(nums)-1-i]
	}

	result := make([]int, len(nums))
	result[0] = fEnd[len(nums)-2]
	result[len(nums)-1] = fStart[len(nums)-2]

	for i := 1; i < len(nums)-1; i++ {
		result[i] = fStart[i-1] * fEnd[len(nums)-2-i]
	}

	return result
}
