package main

import (
	"container/list"
	"fmt"
)

func main() {
	numIslands := numIslands

	fmt.Println(numIslands([][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}))
}

func numIslands(grid [][]byte) int {
	result := 0
	m := len(grid)
	n := len(grid[0])

	visitedLand := make([][]bool, m)
	_mem := make([]bool, m*n)
	for i := range visitedLand {
		visitedLand[i], _mem = _mem[:n], _mem[n:]
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if !visitedLand[i][j] && grid[i][j] == '1' {
				result += 1
				dfs(grid, i, j, visitedLand)
			}
		}
	}

	return result
}

func dfs(graph [][]byte, i int, j int, visited [][]bool) {
	dirs := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
	m := len(graph)
	n := len(graph[0])

	stack := list.New()
	stack.PushBack([2]int{i, j})
	visited[i][j] = true

	for stack.Len() != 0 {
		popIdx := stack.Back().Value.([2]int)
		stack.Remove(stack.Back())

		for _, d := range dirs {
			ti, tj := popIdx[0]+d[0], popIdx[1]+d[1]
			if ti >= 0 && ti < m && tj >= 0 && tj < n && !visited[ti][tj] && graph[ti][tj] == '1' {
				visited[ti][tj] = true
				stack.PushBack([2]int{ti, tj})
			}
		}
	}
}
