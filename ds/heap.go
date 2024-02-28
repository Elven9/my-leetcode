package ds

type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *MinHeap) Push(x any)        { *h = append(*h, x.(int)) }
func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MaxHeap []int

func (h *MaxHeap) Len() int           { return len(*h) }
func (h *MaxHeap) Less(i, j int) bool { return (*h)[i] > (*h)[j] }
func (h *MaxHeap) Swap(i, j int)      { (*h)[i], (*h)[j] = (*h)[j], (*h)[i] }
func (h *MaxHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *MaxHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}

type IntSliceMinHeap [][]int

func (h *IntSliceMinHeap) Len() int { return len(*h) }
func (h *IntSliceMinHeap) Less(i, j int) bool {
	a, b, m := (*h)[i], (*h)[j], len((*h)[i])
	for k := 0; k < m; k++ {
		if a[k] != b[k] {
			return a[k] < b[k]
		}
	}
	return false
}
func (h *IntSliceMinHeap) Swap(i, j int)      { (*h)[i], (*h)[j] = (*h)[j], (*h)[i] }
func (h *IntSliceMinHeap) Push(x interface{}) { *h = append(*h, x.([]int)) }
func (h *IntSliceMinHeap) Pop() interface{} {
	ret := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return ret
}
