package main

func main() {}

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	// Naive solution: scan and record change point
	//
	// Time complexity: O(n), Space complexity: O(1)
	dummy := &ListNode{Next: head, Val: -101}
	cur := head
	lastDiffNode := dummy
	repeat := 0

	for cur != nil {
		repeat++
		if cur.Next != nil && cur.Next.Val != cur.Val {
			if repeat > 1 {
				lastDiffNode.Next = cur.Next
			} else {
				lastDiffNode = cur
			}
			repeat = 0
		}
		cur = cur.Next
	}

	// Last repeat check
	if repeat > 1 {
		lastDiffNode.Next = nil
	}

	return dummy.Next
}
