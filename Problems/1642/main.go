package main

import (
	"container/heap"

	"github.com/Elven9/my-leetcode/ds"
)

func main() {}

func furthestBuilding(heights []int, bricks int, ladders int) int {
	// Naive solution: DFS, with O(2^n), O(n)
	//
	// Implement with min heap
	// Time complexity: O(nlogk), k-> ladders
	minHeap := &ds.MinHeap{}
	heap.Init(minHeap)

	i := 1
	for ; i < len(heights); i++ {
		jmp := heights[i] - heights[i-1]
		if jmp <= 0 {
			continue
		}
		if ladders > 0 {
			heap.Push(minHeap, jmp)
			ladders--
			continue
		}
		if minHeap.Len() != 0 && jmp > (*minHeap)[0] {
			bricks -= (*minHeap)[0]
			(*minHeap)[0] = jmp
			heap.Fix(minHeap, 0)
		} else {
			bricks -= jmp
		}
		if bricks < 0 {
			return i - 1
		}
	}
	if i == len(heights) {
		return i - 1
	}
	return i
}
