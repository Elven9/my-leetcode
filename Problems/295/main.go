package main

import (
	"container/heap"

	"github.com/Elven9/my-leetcode/ds"
)

// SOL
type MedianFinder struct {
	small *ds.MaxHeap
	large *ds.MaxHeap // With Negative Value
}

func Constructor() MedianFinder {
	ret := MedianFinder{
		small: &ds.MaxHeap{},
		large: &ds.MaxHeap{},
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
