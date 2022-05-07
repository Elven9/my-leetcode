package main

import "fmt"

func main() {

	rob := rob_dp

	fmt.Println(rob([]int{1, 2, 3, 1}))
	fmt.Println(rob([]int{2, 7, 9, 3, 1}))
}

func rob_dp(nums []int) int {

	if len(nums) == 1 {
		return nums[0]
	}

	resultTable := make([]int, len(nums))
	resultTable[0] = nums[0]
	resultTable[1] = nums[1]
	if nums[0] > nums[1] {
		resultTable[1] = nums[0]
	}

	for i := 2; i < len(nums); i++ {
		resultTable[i] = resultTable[i-2] + nums[i]
		if resultTable[i-1] > resultTable[i] {
			resultTable[i] = resultTable[i-1]
		}
	}

	return resultTable[len(nums)-1]
}

func rob_recursive(nums []int) int {

	if len(nums) == 0 {
		return 0
	}

	if len(nums) == 1 {
		return nums[0]
	}

	torob := rob_recursive(nums[2:]) + nums[0]
	notRobs := rob_recursive(nums[1:])

	if torob > notRobs {
		return torob
	} else {
		return notRobs
	}
}
