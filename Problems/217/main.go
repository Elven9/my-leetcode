package main

import "fmt"

func main() {

	containsDuplicate := containsDuplicate

	fmt.Println(containsDuplicate([]int{1, 2, 3, 1}))
	fmt.Println(containsDuplicate([]int{1, 2, 3, 4}))
	fmt.Println(containsDuplicate([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}))
}

func containsDuplicate(nums []int) bool {
	// Linear Scan
	// O(n)
	// Add with Hash Table
	table := make(map[int]struct{})

	for _, n := range nums {
		if _, ok := table[n]; ok {
			return true
		}
		table[n] = struct{}{}
	}

	return false
}
