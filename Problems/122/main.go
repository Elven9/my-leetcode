package main

func main() {

}

func maxProfit(prices []int) int {
	min := prices[0]
	profit := 0

	for _, price := range prices {
		if price > min {
			profit += price - min
		}
		min = price
	}

	return profit
}
