package main

import "fmt"

func main() {
	longestConsecutive := longestConsecutive

	fmt.Println(longestConsecutive([]int{100, 4, 200, 1, 3, 2}))
	fmt.Println(longestConsecutive([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}))
	fmt.Println(longestConsecutive([]int{2, -9, 8, -2, 0, 9, -3, 3, -4, 5, -1, -3, 5, 2, 8, -1, 5, 9, 5}))
}

func longestConsecutive(nums []int) int {
	// Naive Solution, O(n)
	resMap := make(map[int]int)

	for _, n := range nums {
		if _, ok := resMap[n]; ok {
			continue
		}

		rightEnd, rok := resMap[n+1]
		leftEnd, lok := resMap[n-1]

		if rok && lok {
			resMap[leftEnd], resMap[rightEnd], resMap[n] = rightEnd, leftEnd, n
		} else {
			if rok {
				resMap[n], resMap[rightEnd] = rightEnd, n
			} else if lok {
				resMap[n], resMap[leftEnd] = leftEnd, n
			} else {
				resMap[n] = n
			}
		}
	}

	// Getting Result
	result := 0
	for k, v := range resMap {
		if v-k+1 > result {
			result = v - k + 1
		}
	}

	return result
}
