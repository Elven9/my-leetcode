package main

import (
	"sort"
	"strconv"
	"strings"
)

func main() {

}

func largestNumber(nums []int) string {
	// Dictionary Sort
	strNums := make([]string, 0)
	resLen := 0

	for _, n := range nums {
		tmp := strconv.Itoa(n)
		resLen += len(tmp)
		strNums = append(strNums, tmp)
	}

	// Sort on String List
	sort.Slice(strNums, func(i, j int) bool { return strNums[i]+strNums[j] > strNums[j]+strNums[i] })

	// Build String
	builder := strings.Builder{}
	builder.Grow(resLen)

	for _, s := range strNums {
		builder.WriteString(s)
	}

	// Remove Front Zero
	res := builder.String()
	for len(res) > 1 && res[0] == '0' {
		res = res[1:]
	}

	return res
}
