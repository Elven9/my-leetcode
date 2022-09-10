package main

func countBits(n int) []int {
	res := make([]int, n+1)

	res[0] = 0

	for i := 1; i < n+1; i++ {
		res[i] = res[i/2] + i&0x1
	}

	return res
}

func countBits_anotherDP(n int) []int {
	// Faster than prev version in run time
	// Cause by computational difference
	res := make([]int, n+1)
	res[0] = 0

	idx := 0
	anchor := 1
	for i := 1; i < n+1; i++ {
		if i == anchor {
			anchor *= 2
			idx = 0
			res[i] = 1
		} else {
			res[i] = res[idx] + 1
		}
		idx++
	}

	return res
}
n
