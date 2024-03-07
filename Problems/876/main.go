package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {}

func middleNode(head *ListNode) *ListNode {
	// Turtle and Rabbit Solution
	// O(n), O(1)
	t, r := head, head
	for r.Next != nil && r.Next.Next != nil {
		t = t.Next
		r = r.Next.Next
	}

	if r.Next != nil {
		return t.Next
	}
	return t
}
