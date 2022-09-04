package main

import "container/heap"

// MaxHeap
type MaxHeap []int

func (h *MaxHeap) Len() int           { return len(*h) }
func (h *MaxHeap) Less(i, j int) bool { return (*h)[i] > (*h)[j] } // MaxHeap
func (h *MaxHeap) Swap(i, j int)      { (*h)[i], (*h)[j] = (*h)[j], (*h)[i] }
func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *MaxHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}

// SOL
type MedianFinder struct {
	small *MaxHeap
	large *MaxHeap // With Negative Value
}

func Constructor() MedianFinder {
	ret := MedianFinder{
		small: &MaxHeap{},
		large: &MaxHeap{},
	}
	heap.Init(ret.small)
	heap.Init(ret.large)
	return ret
}

func (this *MedianFinder) AddNum(num int) {
	if this.large.Len()-this.small.Len() == 0 {
		// even
		heap.Push(this.small, num)
		heap.Push(this.large, -1*heap.Remove(this.small, 0).(int))
	} else {
		heap.Push(this.large, -1*num)
		heap.Push(this.small, -1*heap.Remove(this.large, 0).(int))
	}
}

func (this *MedianFinder) FindMedian() float64 {
	if this.large.Len()-this.small.Len() == 0 {
		// even
		return (float64((*this.large)[0])*-1 + float64((*this.small)[0])) / 2
	} else {
		return float64((*this.large)[0]) * -1
	}
}
