package main

import "fmt"

func main() {

	fmt.Println(rob_dp([]int{2, 3, 2}))
	fmt.Println(rob_dp([]int{1, 2, 3, 1}))
	fmt.Println(rob_dp([]int{1, 2, 3}))
}

func rob_dp(nums []int) int {

	// O(n^2) ??? Every position should take into considiration
	result := -1

	if len(nums) <= 3 {
		for _, v := range nums {
			if v > result {
				result = v
			}
		}
		return result
	}

	for sp := range nums {
		newList := make([]int, len(nums)-3)

		count := (sp + 2) % len(nums)
		for i := range newList {
			newList[i] = nums[count]
			count = (count + 1) % len(nums)
		}

		tmp := nums[sp] + rob_dp_internal(newList)
		if tmp > result {
			result = tmp
		}
	}

	return result
}

func rob_dp_internal(nums []int) int {

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
