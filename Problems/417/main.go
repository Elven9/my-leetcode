package main

import (
	"container/list"
	"fmt"
)

func main() {
	pacificAtlantic := pacificAtlantic_dfsFromEdgeOptimize

	fmt.Println(pacificAtlantic([][]int{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}))
	fmt.Println(pacificAtlantic([][]int{{2, 1}, {1, 2}}))
	fmt.Println(pacificAtlantic([][]int{
		{4, 10, 10, 16, 8, 4, 11, 13, 10, 6, 3, 3, 4, 18, 10, 2, 18, 6, 12, 11, 15, 2, 3, 2, 11, 19, 14, 12, 14, 2, 19, 1, 10, 11, 6, 15, 2},
		{6, 16, 9, 11, 15, 4, 14, 3, 6, 11, 2, 0, 14, 7, 0, 19, 3, 14, 2, 15, 19, 1, 10, 2, 6, 5, 14, 14, 6, 9, 14, 12, 18, 6, 2, 19, 19},
		{0, 11, 0, 17, 3, 8, 3, 1, 11, 7, 17, 8, 16, 6, 5, 0, 13, 7, 10, 14, 7, 15, 1, 7, 11, 18, 0, 4, 6, 5, 7, 10, 17, 6, 8, 0, 13},
		{1, 3, 4, 7, 17, 0, 12, 10, 5, 4, 17, 11, 0, 17, 3, 2, 16, 7, 5, 15, 3, 17, 13, 15, 13, 14, 11, 2, 3, 1, 9, 1, 12, 4, 18, 5, 9},
	}))
}

func pacificAtlantic(heights [][]int) [][]int {
	// Naive solution: DFS on each node
	// O(m*n*m*n) LOL
	result := make([][]int, 0)
	rsize := len(heights)
	csize := len(heights[0])

	for i := 0; i < rsize; i++ {
		for j := 0; j < csize; j++ {
			if dfsWalkToBorder(heights, i, j) {
				result = append(result, []int{i, j})
			}
		}
	}

	return result
}

func dfsWalkToBorder(graph [][]int, x int, y int) bool {
	toAtlantic := false
	toPacific := false
	cSize := len(graph[0])
	maxX := len(graph) - 1
	maxY := len(graph[0]) - 1

	stack := list.New()
	visited := make(map[int]struct{})
	stack.PushBack([2]int{x, y})
	visited[x*cSize+y] = struct{}{}

	for stack.Len() != 0 {
		idx := stack.Back().Value.([2]int)
		stack.Remove(stack.Back())
		if idx[0] == 0 || idx[1] == 0 {
			toPacific = true
		}
		if idx[0] == maxX || idx[1] == maxY {
			toAtlantic = true
		}

		// Check Each Direction
		x := idx[0]
		y := idx[1]
		curVal := graph[x][y]
		// North
		if _, ok := visited[(x-1)*cSize+y]; !ok && x > 0 && graph[x-1][y] <= curVal {
			stack.PushBack([2]int{x - 1, y})
			visited[(x-1)*cSize+y] = struct{}{}
		}
		// East
		if _, ok := visited[(x)*cSize+y+1]; !ok && y < maxY && graph[x][y+1] <= curVal {
			stack.PushBack([2]int{x, y + 1})
			visited[(x)*cSize+y+1] = struct{}{}
		}
		// South
		if _, ok := visited[(x+1)*cSize+y]; !ok && x < maxX && graph[x+1][y] <= curVal {
			stack.PushBack([2]int{x + 1, y})
			visited[(x+1)*cSize+y] = struct{}{}
		}
		// West
		if _, ok := visited[(x)*cSize+y-1]; !ok && y > 0 && graph[x][y-1] <= curVal {
			stack.PushBack([2]int{x, y - 1})
			visited[(x)*cSize+y-1] = struct{}{}
		}
	}

	return toAtlantic && toPacific
}
