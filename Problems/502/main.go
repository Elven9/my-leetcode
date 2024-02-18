package main

import (
	"container/heap"
	"fmt"
	"sort"

	"github.com/Elven9/my-leetcode/ds"
)

func main() {
	testcases := []struct {
		k       int
		w       int
		profits []int
		capital []int
	}{
		{
			2, 0, []int{1, 2, 3}, []int{0, 1, 1},
		},
		{
			1, 2, []int{1, 2, 3}, []int{1, 1, 2},
		},
	}

	for i, tc := range testcases {
		fmt.Printf("Case %d: %v\n", i, findMaximizedCapital(tc.k, tc.w, tc.profits, tc.capital))
	}
}

type pcRatio struct {
	Ratio   float32
	Profit  int
	Capital int
}

type MaxHeap []*pcRatio

func (h *MaxHeap) Len() int { return len(*h) }
func (h *MaxHeap) Less(i, j int) bool {
	a, b := (*h)[i], (*h)[j]
	// Since there is no need for subtracting capital with executed project,
	// we only need to find the maximum profit at the time and execute it.
	/*
		if a.Capital == b.Capital {
			if a.Capital == 0 {
				return a.Profit > b.Profit
			}
			return a.Ratio > b.Ratio
		}
		return a.Capital > b.Capital
	*/
	return a.Profit > b.Profit
}
func (h *MaxHeap) Swap(i, j int)      { (*h)[i], (*h)[j] = (*h)[j], (*h)[i] }
func (h *MaxHeap) Push(x interface{}) { *h = append(*h, x.(*pcRatio)) }
func (h *MaxHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	// Greedy Approach, doing best profits/capital ratio project at the moment
	//
	// - Sort project based on capital
	// - Push ratio on to the max heap
	// - check one by one
	// Time complexity: O(nlogn) + O(klogn), since n == k => O(nlogn)
	// Space complexity: O(nlogn)
	projs := make([]pcRatio, len(profits))
	for i := 0; i < len(profits); i++ {
		projs[i].Profit = profits[i]
		projs[i].Capital = capital[i]
	}

	// Sort by capital
	sort.Slice(projs, func(i, j int) bool { return projs[i].Capital < projs[j].Capital })

	maxRatio, cp := &ds.MaxHeap{}, 0
	// Finished each projects
	for k > 0 {
		// Push available projects
		for cp < len(projs) && projs[cp].Capital <= w {
			heap.Push(maxRatio, projs[cp].Profit)
			cp++
		}

		if maxRatio.Len() == 0 {
			break
		}

		// Finished one project
		cand := heap.Pop(maxRatio).(int)
		w += cand
		k--
	}

	return w
}

func findMaximizedCapital_OriginalThought(k int, w int, profits []int, capital []int) int {
	// Greedy Approach, doing best profits/capital ratio project at the moment
	//
	// - Sort project based on capital
	// - Push ratio on to the max heap
	// - check one by one
	// Time complexity: O(nlogn) + O(klogn), since n == k => O(nlogn)
	// Space complexity: O(n)

	projs := make([]pcRatio, len(profits))
	for i := 0; i < len(profits); i++ {
		projs[i].Profit = profits[i]
		projs[i].Capital = capital[i]
		projs[i].Ratio = float32(profits[i]) / float32(capital[i])
	}

	// Sort by capital
	sort.Slice(projs, func(i, j int) bool { return projs[i].Capital < projs[j].Capital })

	maxRatio, cp := &MaxHeap{}, 0
	// Finished each projects
	for k > 0 {
		// Push available projects
		for cp < len(projs) && projs[cp].Capital <= w {
			heap.Push(maxRatio, &projs[cp])
			cp++
		}

		if maxRatio.Len() == 0 {
			break
		}

		// Finished one project
		cand := heap.Pop(maxRatio).(*pcRatio)
		w += cand.Profit
		k--
	}

	return w
}
