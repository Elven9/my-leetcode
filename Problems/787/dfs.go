package main

import "math"

type dstAndPrice struct {
	Dst   int
	Price int
}

// DFS
func findCheapestPrice_dfs(n int, flights [][]int, src int, dst int, k int) int {
	// 48/53
	// CYCLE Detection with K stops
	// DS: Map with destinition and price
	// Optimized with visited array
	// Optimized with cost to prune

	flightBySrc := make(map[int][]dstAndPrice)
	for _, flight := range flights {
		flightBySrc[flight[0]] = append(flightBySrc[flight[0]], dstAndPrice{flight[1], flight[2]})
	}
	visited := make([]bool, n)

	res := math.MaxInt
	dfs(src, dst, k, 0, flightBySrc, visited, &res)
	if res == math.MaxInt {
		return -1
	}
	return res
}

func dfs(src, dst, k int, price int, fbs map[int][]dstAndPrice, visited []bool, ans *int) {
	if src == dst {
		if price < *ans {
			*ans = price
		}
		return
	}
	if k < 0 {
		return
	}

	// Init
	visited[src] = true
	k--

	// Next Stop
	for _, d := range fbs[src] {
		if visited[d.Dst] || price+d.Price > *ans {
			continue
		}
		dfs(d.Dst, dst, k, price+d.Price, fbs, visited, ans)
	}

	// Out
	visited[src] = false
}
