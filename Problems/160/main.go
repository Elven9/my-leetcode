package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	curA := headA
	curB := headB

	for curA != curB {
		if curA == nil {
			curA = headB
		} else {
			curA = curA.Next
		}

		if curB == nil {
			curB = headA
		} else {
			curB = curB.Next
		}
	}

	return curA
}

func getIntersectionNode_len(headA, headB *ListNode) *ListNode {
	// Naive Solution: O(m*n), w/ SC O(1)
	// With hash map sol: O(m+n), w/ SC O(m)

	// Scan both linked list once, to get m and n
	// Skip abs(m-n) and start to compare

	m := 0
	tmp := headA
	for tmp != nil {
		m++
		tmp = tmp.Next
	}

	n := 0
	tmp = headB
	for tmp != nil {
		n++
		tmp = tmp.Next
	}

	curA := headA // m
	curB := headB // n
	if m > n {
		for i := 0; i < m-n; i++ {
			curA = curA.Next
		}
	} else {
		for i := 0; i < n-m; i++ {
			curB = curB.Next
		}
	}

	// Start to Compare
	for curA != nil && curB != nil {
		if curA == curB {
			return curA
		} else {
			curA = curA.Next
			curB = curB.Next
		}
	}

	return nil
}
