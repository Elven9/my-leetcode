package main

func main() {

}

func merge(nums1 []int, m int, nums2 []int, n int) {
	// Instead from the start, we can sort the array from the end of the input

	cnt := m + n - 1
	m--
	n--

	for m >= 0 && n >= 0 {
		if nums1[m] > nums2[n] {
			nums1[cnt] = nums1[m]
			m--
		} else {
			nums1[cnt] = nums2[n]
			n--
		}
		cnt--
	}

	for m >= 0 {
		nums1[cnt] = nums1[m]
		m--
		cnt--
	}

	for n >= 0 {
		nums1[cnt] = nums2[n]
		n--
		cnt--
	}
}
