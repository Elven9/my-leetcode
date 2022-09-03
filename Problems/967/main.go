package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(numsSameConsecDiff(2, 0))
}

func numsSameConsecDiff(n int, k int) []int {
	result := make([]int, 0)

	for i := 1; i < 10; i++ {
		result = append(result, recurConstruct(n-1, k, i)...)
	}

	return result
}

func recurConstruct(n int, k int, num int) []int {
	if n == 0 {
		return []int{num}
	}
	result := make([]int, 0)
	pd := num % 10
	if k == 0 {
		result = append(result, recurConstruct(n-1, k, num*10+pd)...)
	} else {
		if pd-k >= 0 {
			result = append(result, recurConstruct(n-1, k, num*10+pd-k)...)
		}

		if pd+k < 10 {
			result = append(result, recurConstruct(n-1, k, num*10+pd+k)...)
		}
	}

	return result
}

func numsSameConsecDiff_TLE(n int, k int) []int {
	// Scan through every numbers in the range
	// Check if the sequence is valid
	// Not optimize solution
	// Time Complexity: O(10^(n-1))

	// TLE Version
	result := make([]int, 0)
	limit := int(math.Pow10(n))

FullNumber:
	for i := int(math.Pow10(n - 1)); i < int(limit); i++ {
		// Check if Valid
		tmp := i
		for d := 0; d < n-1; d++ {
			if math.Abs(float64((tmp/10)%10-tmp%10)) != float64(k) {
				continue FullNumber
			}
			tmp /= 10
		}
		result = append(result, i)
	}

	return result
}
