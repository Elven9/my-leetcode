package main

func main() {}

func getCommon(nums1 []int, nums2 []int) int {
	res := -1
	i, j := 0, 0

	for i < len(nums1) && j < len(nums2) {
		if nums1[i] == nums2[j] {
			return nums1[i]
		}
		if nums1[i] <= nums2[j] {
			i++
		} else {
			j++
		}
	}

	return res
}
