package main

func main() {}

func pivotInteger(n int) int {
	sum := (1 + n) * n / 2
	cur := 0

	for i := 1; i <= n; i++ {
		cur += i
		sum -= i - 1
		if cur == sum {
			return i
		}
	}
	return -1
}
