package main

import "fmt"

func main() {

	fmt.Println(findMin([]int{3, 4, 5, 1, 2}))
	fmt.Println(findMin([]int{4, 5, 6, 7, 0, 1, 2}))
	fmt.Println(findMin([]int{11, 13, 15, 17}))
	fmt.Println(findMin([]int{3, 4, 5, 6, 1, 2}))
	fmt.Println(findMin([]int{5, 1, 2, 3, 4}))
	fmt.Println(findMin([]int{1}))
	fmt.Println(findMin([]int{284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42, 43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108, 109, 112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155, 159, 160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200, 203, 204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244, 246, 248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281}))
}

func findMin(nums []int) int {

	// Two Binary Movement
	// O(log n)
	// O(1)

	// Binary Move Toward Max
	start, end, cur := 0, len(nums)-1, (len(nums)-1)/2
	for cur > start && cur < end {
		if nums[cur] < nums[cur-1] && nums[cur] < nums[cur+1] {
			return nums[cur]
		}
		if nums[end] < nums[cur] {
			start = cur + 1
		} else {
			end = cur - 1
		}
		cur = (start + end) / 2
	}

	if cur+1 < len(nums) && nums[cur+1] < nums[cur] {
		return nums[cur+1]
	} else if cur-1 > 0 && nums[cur-1] < nums[cur] {
		return nums[cur-1]
	} else {
		return nums[cur]
	}
}
