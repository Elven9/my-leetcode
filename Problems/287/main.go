package main

import "C"

import "sort"

func main() {}

func findDuplicate(nums []int) int {
	idx := sort.Search(len(nums), func(i int) bool {
		mcnt, cnt := 0, 0
		i++

		for _, n := range nums {
			if n == i {
				mcnt++
			} else if n < i {
				cnt++
			}
		}

		if mcnt > 1 {
			return true
		}

		if cnt <= i-1 {
			return false
		} else {
			return true
		}
	})

	if idx != len(nums) {
		return idx + 1
	}
	return 0
}
