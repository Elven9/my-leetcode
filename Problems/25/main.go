package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	// Goal
	//
	// - 1 2 3 4 5, k = 2
	// - 2 1 3 4 5,
	// - 2 1 4 3 5,
	// - 2 1 4 3 5
	//
	// General Idea: Scan from left to right, reverse every k-nodes linked list
	// O(n), O(1)
	//
	// Implementation Detail
	//
	// [ ] Scan from left right
	// [ ] 開始翻轉點的 stprt, 翻轉紀錄點 edptr 正在翻轉的 cur, 原本下一個 Node nptr
	// [ ] K Counter: kcnt
	// [ ] Scan first time for len (可能可以優化)
	//      - 可以確認最後是否非為倍數的關係下，Not Modified Linked List
	//
	// Other Idea
	// [ ] kcnt 去紀錄，最後以經到 Null 但 kcnt 還不等於 0，把後面重新 Reverse

	// Edge Cases
	if head == nil || k == 1 {
		return head
	}

	// Implementation Simplicity
	res := ListNode{
		Next: head,
	}

	// Ptr Def
	stprt := head
	edptr := head
	prevptr := &res
	cur := head
	var nptr *ListNode

	// Counter Def
	kcnt := k

	for cur != nil {
		nptr = cur.Next
		// 翻轉的動作
		if kcnt == k {
			// Start the sequence
			stprt = cur
			edptr = cur
			edptr.Next = nil
		} else {
			cur.Next = stprt
			stprt = cur
		}

		// 連接斷裂的 Reverse Linked List
		if kcnt == 1 {
			kcnt = k
			prevptr.Next = stprt
			prevptr = edptr
		} else {
			kcnt--
		}

		cur = nptr
	}

	// Reverse back remaining part of the list
	if kcnt != k {
		cur = stprt.Next
		stprt.Next = nil
		for cur != nil {
			nptr = cur.Next
			cur.Next = stprt
			stprt = cur
			cur = nptr
		}
		prevptr.Next = stprt
	}

	return res.Next
}
