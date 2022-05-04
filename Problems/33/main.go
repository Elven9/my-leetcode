package main

import "fmt"

func main() {

	fmt.Println(search([]int{4, 5, 6, 7, 0, 1, 2}, 0))
	fmt.Println(search([]int{4, 5, 6, 7, 0, 1, 2}, 3))
	fmt.Println(search([]int{1}, 0))
	fmt.Println(search([]int{1}, 1))

}

func search(nums []int, target int) int {
	// Binary Search
	// O(n)
	// O(1)
	result := -1
	start, end, cur := 0, len(nums)-1, (len(nums)-1)/2

	for cur >= start && cur <= end {
		// Performance
		if nums[cur] == target {
			result = cur
			break
		}

		if nums[start] == target {
			result = start
			break
		}

		if nums[end] == target {
			result = end
			break
		}

		if target > nums[cur] {
			if nums[end] > nums[cur] && target > nums[end] {
				end = cur - 1
			} else {
				start = cur + 1
			}
		} else if target < nums[cur] {
			if nums[start] < nums[cur] && target < nums[start] {
				start = cur + 1
			} else {
				end = cur - 1
			}
		}
		cur = (start + end) / 2
	}

	return result
}
