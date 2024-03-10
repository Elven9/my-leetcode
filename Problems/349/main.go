package main

func main() {}

func intersection(nums1 []int, nums2 []int) []int {
	// Naive solution, two frequency map, check correspondent with each other
	// O(m+n), O(m+n)
	freq1, freq2 := make(map[int]struct{}), make(map[int]struct{})

	for _, v := range nums1 {
		freq1[v] = struct{}{}
	}
	for _, v := range nums2 {
		freq2[v] = struct{}{}
	}

	// Construct Result
	res := make([]int, 0)

	for k, _ := range freq1 {
		if _, ok := freq2[k]; ok {
			res = append(res, k)
		}
	}

	return res
}
