package main

import (
	"container/heap"
)

func main() {

}

type Item struct {
	Value, Index int

	// Linked List
	Next *Item
}

// Heap Structure
type MaxHeap []*Item

// sort.Interface
func (h MaxHeap) Len() int {
	return len(h)
}
func (h MaxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].Index = i
	h[j].Index = j
}
func (h MaxHeap) Less(i, j int) bool {
	return h[i].Value > h[j].Value
}

// Heap Interface
func (h *MaxHeap) Push(i interface{}) {
	i.(*Item).Index = len(*h)
	*h = append(*h, i.(*Item))
}

func (h *MaxHeap) Pop() interface{} {
	n := len(*h) - 1
	tmp := (*h)[n]
	(*h)[n] = nil
	*h = (*h)[:n]
	return tmp
}

func maxSlidingWindow(nums []int, k int) []int {
	// Goal
	//
	// Maxima number in the interval of the sliding windows ?
	//
	// 移動一次 Windows
	//      - 被刪掉的那個數字，他是最小 + 加入數字最大 -> Maxima = 新加的數字
	//      - Sorting 其中一個數值，未來的某個時間點，必須要取得第二大的數字
	//      - 「下一個 Maxima 未必會是最新的數字」
	//
	// Spec
	//
	// - Linked list 去記住 Sliding Windows 的每個 Items
	// - MaxHeap 去 Maintain Windows 的大小順序

	i, n := 0, len(nums)

	// Create Linked List
	head := &Item{}
	end := head

	// Create Heap
	maxHeap := &MaxHeap{}
	heap.Init(maxHeap)

	for ; i < k; i++ {
		tmp := &Item{
			Value: nums[i],
		}
		heap.Push(maxHeap, tmp)
		end.Next = tmp
		end = end.Next
	}

	res := make([]int, 0)
	res = append(res, (*maxHeap)[0].Value)

	for ; i < n; i++ {
		heap.Remove(maxHeap, head.Next.Index)
		end.Next = &Item{
			Value: nums[i],
		}
		end = end.Next
		head.Next, head.Next.Next = head.Next.Next, nil
		heap.Push(maxHeap, end)
		res = append(res, (*maxHeap)[0].Value)
	}

	return res
}
