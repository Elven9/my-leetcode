package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	Val   int
	Freq  int
	Index int
}

type MaxHeap []*Item

func (h *MaxHeap) Len() int           { return len(*h) }
func (h *MaxHeap) Less(i, j int) bool { return len(*h) > 1 && (*h)[i].Freq > (*h)[j].Freq } // MaxHeap
func (h *MaxHeap) Swap(i, j int) {
	(*h)[i].Index, (*h)[j].Index = (*h)[j].Index, (*h)[i].Index
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}
func (h *MaxHeap) Push(x interface{}) {
	x.(*Item).Index = len(*h)
	*h = append(*h, x.(*Item))
}
func (h *MaxHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	(*h)[len(*h)-1] = nil
	ret.Index = -1
	*h = (*h)[:len(*h)-1]
	return ret
}

func main() {
	fmt.Println(topKFrequent([]int{1, 1, 1, 2, 2, 3}, 2))
}

func topKFrequent(nums []int, k int) []int {
	// Implement w/ heap, w/ time complexity of O(nlogn)
	// Keep update element, than pop every time

	// Memory vs Time Tradeoff
	mh := make(MaxHeap, 0)
	em := make(map[int]*Item)

	heap.Init(&mh)

	// Initialize
	for _, e := range nums {
		if tmp, ok := em[e]; ok {
			// Element exist, update heap
			tmp.Freq += 1
			heap.Fix(&mh, tmp.Index)
		} else {
			// Add New Element
			newE := &Item{
				Val:  e,
				Freq: 1,
			}
			em[e] = newE
			heap.Push(&mh, newE)
		}
	}

	// Return Result
	res := make([]int, 0)
	for i := 0; i < k; i++ {
		res = append(res, heap.Remove(&mh, 0).(*Item).Val)
	}

	return res
}
