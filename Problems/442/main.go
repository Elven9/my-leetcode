package main

func main() {}

func findDuplicates(nums []int) []int {
	// Use nums as the frequency container
	res := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		n := abs(nums[i])
		if nums[n-1] < 0 {
			res = append(res, n)
		} else {
			nums[n-1] *= -1
		}
	}
	return res
}

func abs(in int) int {
	if in < 0 {
		return -1 * in
	}
	return in
}
