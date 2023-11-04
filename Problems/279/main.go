package main

import (
	"math"
)

func main() {}

func numSquares(n int) int {
	dp := make([]int, n+1)
	dp[0] = 0

	for i := 1; i <= n; i++ {
		dp[i] = 1
		root := int(math.Sqrt(float64(i)))

		tmp := 10000
		for j := 1; j <= root; j++ {
			cand := dp[j*j] + dp[i-j*j]
			if cand < tmp {
				tmp = cand
			}
		}
		dp[i] = tmp
	}

	return dp[n]
}
