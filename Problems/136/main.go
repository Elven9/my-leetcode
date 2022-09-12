package main

func singleNumber(nums []int) int {
	res := 0

	for _, e := range nums {
		res ^= e
	}

	return res
}
