package main

func main() {}

func removeDuplicates(nums []int) int {
	k := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[k] = nums[i]
			k++
		}
	}

	return k
}

// Too many redundant assignment operation !!
func removeDuplicates_slower(nums []int) int {
	k, cur, last := 0, 0, -101

	for cur < len(nums) {
		if nums[cur] != last {
			nums[k], last = nums[cur], nums[cur]
			k++
		}

		cur++
	}

	return k
}
