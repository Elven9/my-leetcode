package main

func main() {

}

func longestValidParentheses(s string) int {
	// Goal
	//
	// () ()() (()) (())()
	// Bruteforce
	// n = 2, 3, 4, 5, 6
	//
	// s[0:], s[1:], s[2:], ... s[i:] 得到由 i 開始的字串最大長度
	// O(n^2), O(1), stackptr
	//
	// Optimize
	// DP May Come to Help ?
	//
	// Spec:
	//
	// [ ] Create DP Structure with n+1, Store Longest start from i
	// [ ] Initial dp[n] = 0, dp[n-1] = 0
	// [ ] DP Spec
	//      - s[i] == ')' -> dp[i] = 0
	//      - s[i] == '('
	//          - s[i+1] == ')' -> dp[i] = 2 + dp[i+2]
	//          - s[i+1] == '(' && s[i+dp[i+1]+1] == ')' -> dp[i] = dp[i+1] + 2 + dp[i+dp[i+1]+2]
	//          - else: dp[i] = 0

	// Edge Case
	if len(s) <= 1 {
		return 0
	}

	n := len(s)
	dp := make([]int, n+1)
	s = s + "a"
	res := 0

	dp[n] = 0
	dp[n-1] = 0

	for i := n - 2; i >= 0; i-- {
		if s[i] == ')' {
			dp[i] = 0
		} else {
			if s[i+1] == ')' {
				dp[i] = 2 + dp[i+2]
			} else if s[i+1] == '(' && s[i+dp[i+1]+1] == ')' {
				dp[i] = dp[i+1] + 2 + dp[i+dp[i+1]+2]
			} else {
				dp[i] = 0
			}
		}
		if dp[i] > res {
			res = dp[i]
		}
	}

	return res
}

func longestValidParentheses_Bruteforce(s string) int {
	// Goal
	//
	// () ()() (()) (())()
	// Bruteforce
	// n = 2, 3, 4, 5, 6
	//
	// s[0:], s[1:], s[2:], ... s[i:] 得到由 i 開始的字串最大長度
	// O(n^2), O(1), stackptr
	//
	// Spec:
	//
	// [ ] Create stackptr
	// [ ] Scan from 0 to n
	// [ ] Check longest valid parentheses
	// [ ] Compare to result
	n := len(s)
	res := 0
	sp := 0

	for i := 0; i < n; i++ {
		sp = 1
		for j := i; j < n && sp > 0; j++ {
			if s[j] == ')' {
				sp--
			} else {
				sp++
			}

			if sp == 1 && j-i+1 > res {
				res = j - i + 1
			}
		}
	}

	return res
}
