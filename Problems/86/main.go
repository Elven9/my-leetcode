package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {}

func partition(head *ListNode, x int) *ListNode {

	before, after := &ListNode{}, &ListNode{}
	be, af := before, after

	for head != nil {
		if head.Val < x {
			be.Next = head
			be = be.Next
		} else {
			af.Next = head
			af = af.Next
		}
		head = head.Next
	}

	// Concat
	af.Next = nil
	be.Next = after.Next
	return before.Next
}
