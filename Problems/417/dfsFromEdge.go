package main

import (
	"container/list"
)

func pacificAtlantic_dfsFromEdge(heights [][]int) [][]int {
	// Naive solution: DFS on each node
	// O(m*n*m*n) LOL
	result := make([][]int, 0)
	rsize := len(heights)
	csize := len(heights[0])

	toAtlantic := make(map[int]struct{})
	toPacific := make(map[int]struct{})

	for i := 0; i < rsize; i++ {
		dfsFromEdge(heights, i, 0, toPacific)
		dfsFromEdge(heights, i, csize-1, toAtlantic)
	}

	for j := 0; j < csize; j++ {
		dfsFromEdge(heights, 0, j, toPacific)
		dfsFromEdge(heights, rsize-1, j, toAtlantic)
	}

	// Check Result
	for i := 0; i < rsize; i++ {
		for j := 0; j < csize; j++ {
			_, oka := toAtlantic[i*csize+j]
			_, okp := toPacific[i*csize+j]

			if oka && okp {
				result = append(result, []int{i, j})
			}
		}
	}

	return result
}

func dfsFromEdge(graph [][]int, x int, y int, marker map[int]struct{}) {
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

		// Check Each Direction
		x := idx[0]
		y := idx[1]
		curVal := graph[x][y]

		marker[x*cSize+y] = struct{}{}

		// North
		if _, ok := visited[(x-1)*cSize+y]; !ok && x > 0 && graph[x-1][y] >= curVal {
			stack.PushBack([2]int{x - 1, y})
			visited[(x-1)*cSize+y] = struct{}{}
		}
		// East
		if _, ok := visited[(x)*cSize+y+1]; !ok && y < maxY && graph[x][y+1] >= curVal {
			stack.PushBack([2]int{x, y + 1})
			visited[(x)*cSize+y+1] = struct{}{}
		}
		// South
		if _, ok := visited[(x+1)*cSize+y]; !ok && x < maxX && graph[x+1][y] >= curVal {
			stack.PushBack([2]int{x + 1, y})
			visited[(x+1)*cSize+y] = struct{}{}
		}
		// West
		if _, ok := visited[(x)*cSize+y-1]; !ok && y > 0 && graph[x][y-1] >= curVal {
			stack.PushBack([2]int{x, y - 1})
			visited[(x)*cSize+y-1] = struct{}{}
		}
	}
}
