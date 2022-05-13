package main

type ListNode struct {
	Val  int
	Next *ListNode
}

type MinHeap struct {
	cur int
	mem []*ListNode
}

func (h *MinHeap) Init(size int) {
	h.mem = make([]*ListNode, size+1)
	h.cur = 0
}

func (h *MinHeap) Insert(node *ListNode) {
	if node == nil {
		return
	}
	h.cur += 1
	h.mem[h.cur] = node

	cur, next := h.cur, h.cur/2
	for next > 0 {
		if h.mem[next].Val > h.mem[cur].Val {
			h.mem[next], h.mem[cur] = h.mem[cur], h.mem[next]
		}
		next, cur = next/2, next
	}
}

func (h *MinHeap) GetMin() *ListNode {
	if h.cur == 0 {
		return nil
	}
	res := h.mem[1]

	// Preserve the minHeap structure
	h.mem[1] = h.mem[h.cur]
	h.cur -= 1
	cur := 1
	for {
		if cur*2+1 <= h.cur {
			next := cur * 2
			if h.mem[cur*2+1].Val < h.mem[next].Val {
				next = cur*2 + 1
			}
			if h.mem[cur].Val > h.mem[next].Val {
				h.mem[cur], h.mem[next] = h.mem[next], h.mem[cur]
				cur = next
			} else {
				break
			}
		} else if cur*2 <= h.cur {
			if h.mem[cur].Val > h.mem[cur*2].Val {
				next := cur * 2
				h.mem[cur], h.mem[next] = h.mem[next], h.mem[cur]
				cur = next
			} else {
				break
			}
		} else {
			break
		}
	}

	return res
}

func (h *MinHeap) IsEmpty() bool {
	return h.cur == 0
}

func mergeKLists(lists []*ListNode) *ListNode {
	// Initialize Heap
	minHeap := MinHeap{}
	minHeap.Init(len(lists))

	// Push all list head
	for _, n := range lists {
		minHeap.Insert(n)
	}

	result := minHeap.GetMin()
	if result != nil && result.Next != nil {
		minHeap.Insert(result.Next)
	}

	cur := result
	for !minHeap.IsEmpty() {
		cur.Next = minHeap.GetMin()
		cur = cur.Next
		if cur.Next != nil {
			minHeap.Insert(cur.Next)
		}
	}

	return result
}

func main() {
	testcases := [][]int{{-8, -7, -7, -5, 1, 1, 3, 4}, {-2}, {-10, -10, -7, 0, 1, 3}, {2}}
	resultNode := make([]*ListNode, 0)

	for _, t := range testcases {
		head := &ListNode{Val: t[0]}
		resultNode = append(resultNode, head)
		for i := 1; i < len(t); i++ {
			head.Next = &ListNode{Val: t[i]}
			head = head.Next
		}
	}

	mergeKLists(resultNode)
}
