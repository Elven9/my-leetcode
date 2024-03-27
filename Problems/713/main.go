package main

import "fmt"

func main() {

	testcases := []struct {
		Nums []int
		k    int
	}{
		{
			Nums: []int{10, 5, 2, 6},
			k:    100,
		},
	}

	for _, tc := range testcases {
		fmt.Println(numSubarrayProductLessThanK(tc.Nums, tc.k))
	}

}

func numSubarrayProductLessThanK(nums []int, k int) int {
	// Sliding Windows comes to the rescue !
	// O(n), O(1) !!

	res, cur := 0, nums[0]
	st, ed := 0, 1
	for st < len(nums) {
		if ed <= st {
			ed = st + 1
			cur = nums[st]
		}
		for ed < len(nums) && cur*nums[ed] < k {
			cur *= nums[ed]
			ed++
		}
		if cur < k {
			res += ed - st
		}

		// Next Round
		cur /= nums[st]
		st++
	}

	return res
}

func numSubarrayProductLessThanK_naive(nums []int, k int) int {
	// Naive solution: Scan foward, not previous
	// O(n^2), O(1)
	res := 0
	for i := 0; i < len(nums); i++ {
		cur := 1
		for j := i; j < len(nums); j++ {
			cur *= nums[j]
			if cur < k {
				res++
			} else {
				break
			}
		}
	}
	return res
}
