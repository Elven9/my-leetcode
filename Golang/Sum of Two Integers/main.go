package main

import (
	"fmt"
)

func main() {
	fmt.Println(getSum(1, 2))
	fmt.Println(getSum(3, 2))
	fmt.Println(getSum(-1000, -1000))
}

func getSum(a int, b int) int {
	// Implement an Software Full Adder
	// O(n bits)
	// Initialize 12 bits Adder
	a &= 0xFFF
	b &= 0xFFF

	cnt := 0
	result := 0
	c := 0

	// fmt.Printf("a -> %b, b -> %b\n", a, b)

	for cnt < 12 {
		sum := (a ^ b ^ c) & (0x1 << cnt)
		c = (((a & b) | (b & c) | (a & c)) & (0x1 << cnt)) << 1
		result |= sum
		// fmt.Printf("Cnt: %d, (%b, %b) -> %b\n", cnt, sum, c, result)
		cnt++
	}

	if (result & 0x800) > 0 {
		result = ((result ^ 0xFFF) + 1) * -1
	}

	return result
}
