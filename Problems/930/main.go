package main

import "fmt"

func main() {

	testcases := []struct {
		nuns []int
		goal int
	}{
		// {
		// 	[]int{1, 0, 1, 0, 1},
		// 	2,
		// },
		// {
		// 	[]int{0, 0, 0, 0, 0},
		// 	0,
		// },
		// {
		// 	[]int{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		// 	0,
		// },
		{
			[]int{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
			3,
		},
	}

	for _, tc := range testcases {
		fmt.Println(numSubarraysWithSum(tc.nuns, tc.goal))
	}
}

func numSubarraysWithSum(nums []int, goal int) int {
	// Sliding Windows, O(n), O(1)
	// Finding minima range of 1-1 subarray, than check left and right zero sequence
	lz, rz, st, ed := 0, 0, -1, 0
	res := 0

	// Goal == 0 cases, optimization
	if goal == 0 {
		// Every combination of sequence of zero is fine
		for ed < len(nums) {
			for ed < len(nums) && nums[ed] == 0 {
				lz++
				ed++
			}
			res += (lz + 1) * lz / 2
			lz = 0
			ed++
		}
		return res
	}

	// Init
	for ed < len(nums) && goal != 0 {
		goal -= nums[ed]
		if st == -1 && nums[ed] == 1 {
			st = ed
		}
		if st == -1 {
			lz++
		}
		ed++
	}
	for tmp := ed; tmp < len(nums) && nums[tmp] == 0; tmp++ {
		rz++
	}
	if goal != 0 {
		return 0
	}

	// Calculate
	for ed < len(nums) || goal == 0 {
		if lz != 0 && rz != 0 {
			res += (lz + 1) * (rz + 1)
		} else {
			res += lz + rz + 1
		}

		// Update Next Parameter
		lz, rz = 0, 0
		st++
		for st < ed && nums[st] == 0 {
			lz++
			st++
		}
		goal++
		for ed < len(nums) && goal != 0 {
			goal -= nums[ed]
			ed++
		}
		for tmp := ed; tmp < len(nums) && nums[tmp] == 0; tmp++ {
			rz++
		}
	}

	return res
}
