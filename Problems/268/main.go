package main

func missingNumber(nums []int) int {
	// Naive solution: Sort and linear scan, which takes O(nlogn).
	//
	// Follow up question: Do it in O(n) time complexity and O(1) space requirement
	//
	// Can be done in xor, summation of numbers and index
	final := len(nums)
	for i := 0; i < len(nums); i++ {
		final ^= i ^ nums[i]
	}
	return final
}
