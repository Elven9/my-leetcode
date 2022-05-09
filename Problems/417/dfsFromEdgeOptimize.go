package main

import "container/list"

func pacificAtlantic_dfsFromEdgeOptimize(heights [][]int) [][]int {
	// Naive solution: DFS on each node
	// O(m*n*m*n) LOL
	result := make([][]int, 0)
	rsize := len(heights)
	csize := len(heights[0])

	toAtlantic := make([][]bool, rsize)
	toPacific := make([][]bool, rsize)

	_aList := make([]bool, rsize*csize)
	_pList := make([]bool, rsize*csize)

	for i := range toAtlantic {
		toAtlantic[i], _aList = _aList[:csize], _aList[csize:]
		toPacific[i], _pList = _pList[:csize], _pList[csize:]
	}

	pStack := list.New()
	aStack := list.New()

	for i := 0; i < rsize; i++ {
		pStack.PushBack([2]int{i, 0})
		toPacific[i][0] = true
		aStack.PushBack([2]int{i, csize - 1})
		toAtlantic[i][csize-1] = true
	}

	for j := 0; j < csize; j++ {
		pStack.PushBack([2]int{0, j})
		toPacific[0][j] = true
		aStack.PushBack([2]int{rsize - 1, j})
		toAtlantic[rsize-1][j] = true
	}

	dfsFromEdge_optimize(heights, pStack, toPacific)
	dfsFromEdge_optimize(heights, aStack, toAtlantic)

	// Check Result
	for i := 0; i < rsize; i++ {
		for j := 0; j < csize; j++ {
			if toAtlantic[i][j] && toPacific[i][j] {
				result = append(result, []int{i, j})
			}
		}
	}

	return result
}

func dfsFromEdge_optimize(graph [][]int, stack *list.List, visited [][]bool) {
	cSize := len(graph[0])
	rSize := len(graph)

	dirs := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}

	for stack.Len() != 0 {
		idx := stack.Back().Value.([2]int)
		stack.Remove(stack.Back())

		// Check Each Direction
		for _, dir := range dirs {
			i, j := idx[0]+dir[0], idx[1]+dir[1]
			if i >= 0 && i < rSize && j >= 0 && j < cSize && !visited[i][j] && graph[i][j] >= graph[idx[0]][idx[1]] {
				stack.PushBack([2]int{i, j})
				visited[i][j] = true
			}
		}
	}
}
