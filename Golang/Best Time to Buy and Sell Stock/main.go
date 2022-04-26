package main

import (
	"fmt"
)

func main() {

	maxProfit := maxProfit_scan

	fmt.Println(maxProfit([]int{7, 1, 5, 3, 6, 4}))
	fmt.Println(maxProfit([]int{7, 6, 4, 3, 1}))
}

func maxProfit_double_loop(prices []int) int {
	// O(n^2)
	// Completely TLE LOL

	result := 0

	for i := 0; i < len(prices); i++ {
		for j := i + 1; j < len(prices); j++ {
			if prices[j]-prices[i] > result {
				result = prices[j] - prices[i]
			}
		}
	}

	return result
}

func maxProfit_scan(prices []int) int {
	// Should be O(n)
	bestProfit := 0
	minPrice := prices[0]

	for i := 1; i < len(prices); i++ {
		if prices[i] < minPrice {
			minPrice = prices[i]
			continue
		}
		p := prices[i] - minPrice
		if p > bestProfit {
			bestProfit = p
		}
	}

	return bestProfit
}
