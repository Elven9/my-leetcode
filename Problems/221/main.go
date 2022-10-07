package main

func main() {

}

func maximalSquare(matrix [][]byte) int {
	// Bruteforce Solutioin: Scan Square by Square, from size 1 to min(m, n)
	// O(m*n * n*n) if min(m, n) = n, Space: O(1)

	// Memoization solution
	m := len(matrix)
	n := len(matrix[0])

	// Create Dp Table
	dp := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n+1)
	}

	res := 0
	// Construct DP Table
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == '1' {
				dp[i+1][j+1] = dp[i][j]
				if dp[i][j+1] < dp[i+1][j+1] {
					dp[i+1][j+1] = dp[i][j+1]
				}
				if dp[i+1][j] < dp[i+1][j+1] {
					dp[i+1][j+1] = dp[i+1][j]
				}
				dp[i+1][j+1] += 1
				if dp[i+1][j+1] > res {
					res = dp[i+1][j+1]
				}
			}
		}
	}

	return res * res
}
