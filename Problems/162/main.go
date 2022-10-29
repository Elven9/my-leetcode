package main

import "sort"

func main() {}

/*
Example
Input: [4, 6, 3, 4, 7, 8]
Output: 6 or 8

Algo 1: O(n), Scanning Whole List

function Algo1(list of elements) {
	for each element {
		if previous element < element && next element < elment {
			return element
		}
	}
}

O(n)

Algo 2: O(log n)
Example 1: [4, 6, 3, 4, 7, 8]

[4, 6, 3], [4, 7, 8], Possible Solution will be Binary Search ?

IN 2: [1, 2, 3, 4, 5, 6, 7]
Out: 7

Important Point: No need to find all peaks
Local minimum

4 Left -> 3, Right -> 5
[1, 4, 3, 4, 5, 6, 7]

IN 2: [1, 2, 3, 4, 5, 6, 7]

Step 1: Medium Point will be 4
Step 2: MP will be 6
Step 3: MP will be 7

Return 7

function Algo2(list of elements) {
	start, end, middle
	BinarySearch on List of Elments {
		if element to the left of middle < middle && element to the right of middle < middle {
			return element (One of peak)
		}

		if element to the left of middle < middle {
			start = middle + 1
		} else {
			end = middle
		}
	}
}

*/

func findPeakElement(nums []int) int {
	res := sort.Search(len(nums), func(i int) bool {
		leftLess := i == 0 || nums[i-1] < nums[i]
		rightLess := i == len(nums)-1 || nums[i+1] < nums[i]

		return !leftLess || rightLess
	})

	return res
}
