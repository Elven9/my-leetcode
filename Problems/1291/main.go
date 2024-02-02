package main

import (
	"math"
)

func main() {}

func sequentialDigits(low int, high int) []int {
	res := make([]int, 0)
	countDigit := func(n int) (count int) {
		for n > 0 {
			count++
			n /= 10
		}
		return count
	}
	construct := func(digit, last int) (res int) {
		for i := 0; i < digit; i++ {
			res += last * int(math.Pow10(i))
			last--
		}
		return res
	}

	// Find initial last and digit
	digit := countDigit(low)
	last := digit
	for construct(digit, last) < low {
		last++
		if last == 10 {
			digit++
			last = digit
		}
	}

	for {
		// Construct Target
		target := construct(digit, last)
		// Add to res
		if target > high {
			break
		}
		res = append(res, target)
		last++

		// Change Digit and Last
		if last == 10 {
			digit++
			last = digit
		}
	}

	return res
}

func sequentialDigitsTLE(low int, high int) []int {
	// Naive solution, iterate through all numbers and check
	res := make([]int, 0)

	check := func(n int) bool {
		cur := n % 10
		n /= 10
		for n > 0 {
			tmp := n % 10
			if tmp+1 != cur {
				return false
			}
			cur = tmp
			n /= 10
		}
		return true
	}

	for i := low; i < high; i++ {
		if check(i) {
			res = append(res, i)
		}
	}

	return res
}
