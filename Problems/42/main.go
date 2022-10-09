package main

func main() {

}

func trap(height []int) int {
	// Goal

	// Brute Force: Scan for Every Height of The Water and Add the Result
	// It takes O(nh), where h equals to max height of all walls
	// Space O(1)

	// Stack based solution
	// To remeber pair of walls and previous level of the water calculated
	// O(n), O(n)

	// Spec
	//
	// [ ] Stack
	// [ ] Condition: Stack only contains element that's greater than h[i]
	// [ ] Last calculated level only calculated when the water is add to res

	if len(height) <= 2 {
		return 0
	}

	res := 0
	stack := make([]int, 20000)
	sp := -1

	for i, v := range height {
		for sp != -1 && v > height[stack[sp]] {
			top := stack[sp]
			sp--

			if sp != -1 {
				res += (min(height[stack[sp]], v) - height[top]) * (i - stack[sp] - 1)
			}
		}
		sp++
		stack[sp] = i
	}

	return res
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func trap_brute(height []int) int {
	// Goal

	// Brute Force: Scan for Every Height of The Water and Add the Result
	// It takes O(nh), where h equals to max height of all walls
	// Space O(1)

	res := 0
	level := 1
	toCont := true
	var prev int
	for toCont {
		prev = -1
		toCont = false

		// Scan through each wall
		for i, v := range height {
			if v >= level {
				if prev != -1 {
					res += i - prev - 1
					prev = i
					toCont = true
				} else {
					prev = i
				}
			}
		}

		level++
	}

	return res
}
