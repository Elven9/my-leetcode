package main

import "fmt"

func main() {

	coinChange := coinChange

	fmt.Println(coinChange([]int{1, 2, 5}, 11))
	fmt.Println(coinChange([]int{2}, 3))
	fmt.Println(coinChange([]int{1}, 0))
}

func coinChange(coins []int, amount int) int {
	// DP Bottom UP
	// O(n)
	// with no improvement
	bc := make([]int, amount+1)
	for i := range bc {
		bc[i] = -1
	}
	bc[0] = 0

	for i := 1; i <= amount; i++ {
		counts := 100000
		for _, c := range coins {
			t := i - c
			if t >= 0 && bc[t] != -1 && bc[t]+1 < counts {
				counts = bc[t] + 1
			}
		}
		if counts != 100000 {
			bc[i] = counts
		}
	}

	return bc[amount]
}
