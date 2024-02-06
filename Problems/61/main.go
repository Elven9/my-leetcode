package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {}

func rotateRight(head *ListNode, k int) *ListNode {
	// Get list length first for optimization k
	// Scan again for cutting points, concat
	//
	// Time complexity: O(n), space complexity: O(1)

	m := 0
	tmp := head
	end := head
	for tmp != nil {
		m++
		if tmp.Next == nil {
			end = tmp
		}
		tmp = tmp.Next
	}
	if m == 0 {
		return nil
	}

	// Calculate Cutting Point
	cutPt := m - k%m - 1
	tmp = head
	for cutPt > 0 {
		tmp = tmp.Next
		cutPt--
	}

	// Concat
	res := tmp.Next
	end.Next = head
	tmp.Next = nil
	if res == nil {
		return head
	}
	return res
}
