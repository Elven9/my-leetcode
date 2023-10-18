package main

func main() {}

func removeDuplicates(nums []int) int {
	k, two_cnt := 1, 1

	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[k] = nums[i]
			k++
			two_cnt = 1
			continue
		}
		if two_cnt < 2 {
			nums[k] = nums[i]
			k++
			two_cnt++
		}
	}
	return k
}
