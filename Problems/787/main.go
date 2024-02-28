package main

import (
	"fmt"
)

func main() {
	testcases := []struct {
		n       int
		flights [][]int
		src     int
		dst     int
		k       int
	}{
		{
			n:       5,
			flights: [][]int{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}},
			src:     0,
			dst:     3,
			k:       2,
		},
	}

	for _, tc := range testcases {
		fmt.Println(findCheapestPrice(tc.n, tc.flights, tc.src, tc.dst, tc.k))
	}
}
