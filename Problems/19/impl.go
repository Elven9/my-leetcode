package p19

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	// Naive solution O(n)
	length := 0

	// Check length
	cur := head
	for cur != nil {
		length++
		cur = cur.Next
	}

	b4target := length - n - 1
	if b4target == -1 {
		return head.Next
	}

	cur = head
	for i := 0; i < b4target; i++ {
		cur = cur.Next
	}
	cur.Next = cur.Next.Next

	return head
}
