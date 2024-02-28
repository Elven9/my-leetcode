package main

import (
	"container/heap"

	"github.com/Elven9/my-leetcode/ds"
)

type Vertex struct {
	ID    int
	Edges []Edge
	InSP  bool
}

type Edge struct {
	To     int
	Weight int
}

type HeapItem struct {
	Cost int
	ID   int
	Stop int
}

type MinHeap []*HeapItem

func (h MinHeap) Len() int { return len(h) }
func (h MinHeap) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.Cost < b.Cost
}
func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *MinHeap) Push(x any) {
	*h = append(*h, x.(*HeapItem))
}
func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Greedy strategy only, dijkstra variation
// 48/53, TLE = =
func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	// Create Vertics
	vertices := make([]Vertex, n)
	for i := 0; i < n; i++ {
		vertices[i].ID = i
	}
	// Create Edges
	for _, f := range flights {
		vertices[f[0]].Edges = append(vertices[f[0]].Edges, Edge{To: f[1], Weight: f[2]})
	}
	// Create heap
	minHeap := &MinHeap{}
	heap.Push(minHeap, &HeapItem{0, src, 0})
	k++

	// Shortest Path stack
	spStack := &ds.IntStack{}
	spStack.Init(n)

	for minHeap.Len() != 0 {
		top := heap.Remove(minHeap, 0).(*HeapItem)
		if top.ID == dst {
			return top.Cost
		}
		if top.Stop == k {
			continue
		}
		// Clean Stack to Correct Level
		for spStack.Size() > top.Stop+1 {
			vertices[spStack.Pop()].InSP = false
		}
		if vertices[top.ID].InSP {
			continue
		}
		spStack.Push(top.ID)
		vertices[top.ID].InSP = true

		for _, edge := range vertices[top.ID].Edges {
			heap.Push(minHeap, &HeapItem{top.Cost + edge.Weight, edge.To, top.Stop + 1})
		}
	}
	return -1
}
