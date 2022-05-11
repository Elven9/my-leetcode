package main

import "fmt"

func main() {
	canJump := canJump
	fmt.Println(canJump([]int{2, 3, 1, 1, 4}))
	fmt.Println(canJump([]int{3, 2, 1, 0, 4}))
	fmt.Println(canJump([]int{13055, 19141, 12848, 11888, 1185, 9905, 3984, 14772, 18935, 6844, 9851, 13695, 17955, 16359, 14969, 6200, 13436, 16940, 13893, 1639, 3233, 11861, 13475, 11963, 8193, 3413, 10952, 8585, 13807, 6320, 4507, 1743, 454, 7983, 9677, 8348, 2496, 4585, 11022, 9103, 1096, 6770, 6745, 4350, 2334, 13024, 2738, 9444, 1028, 5337, 2446, 272, 5799, 7397, 15000, 4848, 16772, 12860, 11773, 196, 3187, 14016, 1314, 1684, 19858, 2598, 16111, 10577, 1643, 12252, 5835, 2819, 17898, 18210, 799, 5010, 19937, 1285, 9693, 18155, 484, 9184, 7212, 3474, 14630, 18418, 10108, 1735, 3940, 2877, 18007, 14731, 10133, 10470, 15396, 7464, 6936, 261}))
	fmt.Println(canJump([]int{0, 1}))
}

func canJump(nums []int) bool {
	remainStamina := make([]int, len(nums)+1)
	remainStamina[0] = 0

	for i := 1; i < len(nums); i++ {
		remainStamina[i] = remainStamina[i-1] - 1
		if nums[i-1] > remainStamina[i] {
			remainStamina[i] = nums[i-1]
		}

		if remainStamina[i] <= 0 {
			return false
		}

		// Edge Case
		if remainStamina[i] >= len(nums)-1 {
			return true
		}
	}

	return remainStamina[len(nums)-1] >= 0
}

// Naive solution, there should be at least one solution that is better than this
func canJump_n2(nums []int) bool {
	// O(n^2)
	table := make([]bool, len(nums))
	table[0] = true

	// Update every point
	for i := 0; i < len(nums)-1; i++ {
		if !table[i] {
			continue
		}

		// Some Edge Case
		if nums[i] >= len(nums)-1 {
			return true
		}

		limit := i + nums[i]
		for j := i + 1; j < len(nums) && j <= limit; j++ {
			table[j] = true
		}
	}

	return table[len(table)-1]
}

// Skip recursion solution
