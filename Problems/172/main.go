package main

func main() {}

func trailingZeroes(n int) int {

	// !!!!
	// In the n! operation, factors 2 is always ample.
	// https://leetcode.com/problems/factorial-trailing-zeroes/solutions/52371/my-one-line-solutions-in-3-languages/?orderBy=most_votes

	// res := 0
	cnt5 := 0
	// cnt2 := 0

	for i := 1; i <= n; i++ {
		num := i
		// Extract 2
		// for num%2 == 0 {
		// 	cnt2++
		// 	num /= 2
		// }

		// Extract 5
		for num%5 == 0 {
			cnt5++
			num /= 5
		}

		// Count 0
		// for cnt2 > 0 && cnt5 > 0 {
		// 	cnt2--
		// 	cnt5--
		// 	res++
		// }
	}

	return cnt5
}
