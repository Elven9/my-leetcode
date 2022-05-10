package main

import "fmt"

func main() {
	fmt.Println(uniquePaths(3, 7))
	fmt.Println(uniquePaths(3, 2))
}

func uniquePaths(m int, n int) int {
	table := make([][]int, m+1)
	_mem := make([]int, (m+1)*(n+1))
	for i := range table {
		table[i], _mem = _mem[:n+1], _mem[n+1:]
	}
	table[m-1][n] = 1

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			table[i][j] = table[i+1][j] + table[i][j+1]
		}
	}

	return table[0][0]
}

// I am skipping recursive version of solution for this classic problem
