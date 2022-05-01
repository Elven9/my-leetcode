package main

import "fmt"

func main() {

	lengthOfLIS := lengthOfLIS

	// fmt.Println(lengthOfLIS([]int{10, 9, 2, 5, 3, 7, 101, 18}))
	// fmt.Println(lengthOfLIS([]int{0, 1, 0, 3, 2, 3}))
	// fmt.Println(lengthOfLIS([]int{7, 7, 7, 7, 7, 7, 7}))
	fmt.Println(lengthOfLIS([]int{1, 3, 6, 7, 9, 4, 10, 5, 6}))
}

func lengthOfLIS(nums []int) int {
	// Time Complexity: O(n^2)
	// Space Complexity: O(n)
	lenRecords := make([]int, len(nums))
	result := 0

	for idx, n := range nums {
		lenRecords[idx] = 1
		// Check Every Length
		for i := 0; i < idx; i++ {
			if n > nums[i] && lenRecords[i]+1 > lenRecords[idx] {
				lenRecords[idx] = lenRecords[i] + 1
			}
		}
		if lenRecords[idx] > result {
			result = lenRecords[idx]
		}
	}

	return result
}
