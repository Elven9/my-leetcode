package main

import "fmt"

func main() {

	climbStairs := climbStairs_bottomup

	fmt.Println(climbStairs(2))
	fmt.Println(climbStairs(3))
}

func climbStairs_bottomup(n int) int {
	// Bottomup
	// O(n)
	stairs_count := make([]int, n)
	stairs_count[0] = 1
	if n > 1 {
		stairs_count[1] = 2
	}

	for i := 2; i < n; i++ {
		// Start with stair case 3
		stairs_count[i] = stairs_count[i-1] + stairs_count[i-2]
	}

	return stairs_count[n-1]
}
