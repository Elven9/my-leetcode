package main

func main() {}

func combinationSum4(nums []int, target int) int {
	table := make([]int, target+1)
	table[0] = 1

	for t := 1; t <= target; t++ {
		for _, num := range nums {
			if t-num < 0 {
				continue
			}
			table[t] += table[t-num]
		}
	}

	return table[target]
}

func combinationSum4_Recursion(nums []int, target int) int {
	// Different sequences are counted as different combinations.
	// TLE Version

	if target == 0 {
		return 1
	}
	if target < 0 {
		return 0
	}

	res := 0
	for _, num := range nums {
		res += combinationSum4_Recursion(nums, target-num)
	}

	return res
}
