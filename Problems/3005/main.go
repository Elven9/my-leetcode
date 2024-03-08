package main

func main() {}

func maxFrequencyElements(nums []int) int {
	// O(n)
	freq := make(map[int]int)
	for _, n := range nums {
		freq[n]++
	}

	// Check
	best, res := -1, 0
	for _, v := range freq {
		if v > best {
			best = v
			res = v
		} else if v == best {
			res += v
		}
	}

	return res
}
