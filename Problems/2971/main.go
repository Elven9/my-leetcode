package main

import "sort"

func main() {}

func largestPerimeter(nums []int) int64 {
	// The longest side of a polygon is smaller than the sum of its other sides.
	// Naive solution: generate each polygon and get max perimeter
	//
	// Simple solution: sort and find first viable polygon
	// Time complexity: O(nlogn), Space complexity: O(1)
	var sum int64 = 0
	for _, n := range nums {
		sum += int64(n)
	}

	// Sort the nums
	sort.Ints(nums)
	for i := len(nums) - 1; i >= 0; i-- {
		n := int64(nums[i])
		tmp := sum - int64(nums[i])
		if n < tmp {
			return sum
		}
		sum -= n
	}

	return -1
}
