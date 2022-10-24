package main

func main() {}

func subsets(nums []int) [][]int {
	buf := make([]int, 0, len(nums))
	return backtrack(nums, buf, 0)
}

func backtrack(nums, buf []int, start int) [][]int {
	res := make([][]int, 0, 1)
	tmp := make([]int, len(buf))
	copy(tmp, buf)
	res = append(res, tmp)
	for i := start; i < len(nums); i++ {
		buf = append(buf, nums[i])
		res = append(res, backtrack(nums, buf, i+1)...)
		buf = buf[:len(buf)-1]
	}
	return res
}
