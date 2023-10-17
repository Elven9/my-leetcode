package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {}

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	c1 := &head
	c2 := &head.Next
	c3 := &head.Next.Next

	for {
		tmp := *c1
		*c1 = *c2
		*c2 = *c3
		*c3 = tmp

		if *c2 != nil && (**c2).Next != nil {
			c1 = c2
			// It can be (*c2) only (implicit selector)
			c2 = &(**c2).Next
			c3 = &(**c2).Next
		} else {
			break
		}

	}

	return head
}
