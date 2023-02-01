package main

import (
	"math"
	"sort"
)

func main() {}

func mySqrt(x int) int {
	// Why not just use x/2 ?
	// Edge case: x == 1
	t := sort.Search(int(math.Ceil(float64(x)/2)), func(i int) bool {
		return i*i >= x
	})
	if int(math.Pow(float64(t), 2)) > x {
		return t - 1
	} else {
		return t
	}
}
