package main

func main() {}

func rearrangeArray(nums []int) []int {
	// Scan once and move pos, neg pointer
	//
	// Time complexity: O(n), Space Complexity: O(n), for storing new array
	res := make([]int, len(nums))
	pos, neg := 0, 1

	// Start populating res array
	for _, n := range nums {
		if n > 0 {
			// Positive
			res[pos] = n
			pos += 2
		} else {
			res[neg] = n
			neg += 2
		}
	}

	return res
}

func rearrangeArray_Naive(nums []int) []int {
	// Naive solution, with two pointer, one record positive number, one for negative number
	//
	// Time complexity: O(n), Space Complexity: O(n), for storing new array
	res := make([]int, len(nums))
	pos, neg := 0, 0

	// Start populating res array
	for i := 0; i < len(res); i++ {
		if i%2 == 0 {
			// Positive
			for nums[pos] < 0 {
				pos++
			}
			res[i] = nums[pos]
			pos++
		} else {
			for nums[neg] > 0 {
				neg++
			}
			res[i] = nums[neg]
			neg++
		}
	}

	return res
}
