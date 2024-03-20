package main

func main() {}

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	b -= a
	// Finding a-1
	cs := list1
	for a > 1 {
		cs = cs.Next
		a--
	}
	// Finding b+1
	ce := cs.Next
	for b > 0 {
		ce = ce.Next
		b--
	}
	ce = ce.Next

	// Concat
	cs.Next = list2
	for list2.Next != nil {
		list2 = list2.Next
	}
	list2.Next = ce

	return list1
}
