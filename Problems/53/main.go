package main

import "fmt"

func main() {

	maxSubArray := maxSubArray

	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
	fmt.Println(maxSubArray([]int{1}))
	fmt.Println(maxSubArray([]int{5, 4, -1, 7, 8}))

}

func maxSubArray(nums []int) int {
	// DP
	// O(n)
	// Space: O(n)
	result := make([]int, len(nums))
	inc := make([]int, len(nums))

	result[0] = nums[0]
	inc[0] = nums[0]

	for i := 1; i < len(nums); i++ {
		inc[i] = nums[i]
		if inc[i-1]+nums[i] > inc[i] {
			inc[i] = inc[i-1] + nums[i]
		}

		result[i] = result[i-1]
		if inc[i] > result[i] {
			result[i] = inc[i]
		}
	}

	return result[len(nums)-1]
}
