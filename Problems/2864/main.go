package main

import "strings"

func main() {}

func maximumOddBinaryNumber(s string) string {
	// Scan and construct ...
	// O(n), O(n)
	oneCount := 0
	for _, r := range s {
		if r == '1' {
			oneCount++
		}
	}
	construct := func(leading, zero int) string {
		return strings.Repeat("1", leading) + strings.Repeat("0", zero) + "1"
	}

	if oneCount == 1 {
		return construct(0, len(s)-1)
	}
	return construct(oneCount-1, len(s)-oneCount)
}
