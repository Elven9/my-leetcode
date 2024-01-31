package main

import (
	"sort"
)

func main() {}

func twoSum(numbers []int, target int) []int {
	// No map, since the solution is required to use constant space

	// Binary search on target from 1 to target
	// => logn
	for i := 0; i < len(numbers); i++ {
		res := sort.Search(len(numbers), func(j int) bool {
			// [Requirement]: You may not use the same element twice.
			// FAIL TESTCASE: [0, 0, 3, 4]
			return numbers[i]+numbers[j] >= target && j != i
		})
		if res != len(numbers) && numbers[res]+numbers[i] == target {
			tmp := sort.IntSlice{res + 1, i + 1}
			sort.Sort(tmp)
			return tmp
		}
	}
	return []int{-1, -1}
}
