package main

import (
	"strconv"
	"strings"
)

func main() {}

func countAndSay(n int) string {
	// Simple Recursive Problems
	if n == 1 {
		return "1"
	}

	target := countAndSay(n - 1)

	// Start To Processing
	builder := strings.Builder{}
	cur := target[0]
	count := 1

	for i := 1; i < len(target); i++ {
		if target[i] != cur {
			builder.WriteString(strconv.Itoa(count))
			builder.WriteByte(cur)
			cur = target[i]
			count = 1
		} else {
			count++
		}
	}
	builder.WriteString(strconv.Itoa(count))
	builder.WriteByte(cur)

	return builder.String()
}
