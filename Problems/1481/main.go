package main

import "sort"

func main() {}

func findLeastNumOfUniqueInts(arr []int, k int) int {
	// Naive solution, scan once, record count, remove num with least amount
	//
	// O(nlogn), O(n)
	// Using heap for O(n+klogn)
	counter := make(map[int]int)
	for _, n := range arr {
		counter[n]++
	}

	// get keys
	amount := make([]int, 0)
	for _, v := range counter {
		amount = append(amount, v)
	}

	sort.Ints(amount)

	i := 0
	for i < len(amount) {
		k -= amount[i]
		i++
		if k < 0 {
			break
		}
	}

	if k == 0 {
		return len(amount) - i
	}
	return len(amount) - i + 1
}
