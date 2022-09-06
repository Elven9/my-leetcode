package main

func maxArea(height []int) int {
	res := 0
	i, j := 0, len(height)-1

	for i < j {
		cand := (j - i) * min(height[i], height[j])

		if cand > res {
			res = cand
		}

		if height[i] < height[j] {
			i += 1
		} else if height[i] > height[j] {
			j -= 1
		} else {
			i += 1
			j -= 1
		}
	}

	return int(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
