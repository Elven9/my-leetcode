package main

func main() {}

func minSubArrayLen(target int, nums []int) int {
	// Naive solution: slide throught whole list
	// Time complexity: O(nlogn), space complexity: O(1)
	if len(nums) == 0 {
		return 0
	}

	res := 100001
	st, ed, sum := 0, 1, nums[0]

	// Sliding windows
	for st < len(nums) && !(ed == len(nums) && sum < target) {
		for sum < target && ed < len(nums) {
			sum += nums[ed]
			ed++
		}

		tmp := ed - st
		if sum >= target && tmp < res {
			res = tmp
		}
		sum -= nums[st]
		st++
	}

	if res == 100001 {
		return 0
	}
	return res
}
