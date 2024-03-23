package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	head := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val: 3,
				Next: &ListNode{
					Val: 4,
					Next: &ListNode{
						Val: 5,
					},
				},
			},
		},
	}

	reorderList(head)
}

func reorderList(head *ListNode) {
	// O(n)
	// Space O(n)
	if head.Next == nil {
		return
	}

	// Create reverse links and get length
	var revLink *ListNode = nil
	length := 0

	cur := head
	for cur != nil {
		length++
		tmp := &ListNode{
			Val:  cur.Val,
			Next: revLink,
		}
		revLink = tmp
		cur = cur.Next
	}

	cur = head
	limit := length / 2
	for i := 0; i < limit; i++ {
		tmp := cur.Next
		cur.Next, revLink = revLink, revLink.Next
		if i == limit-1 {
			if length%2 == 1 {
				cur.Next.Next = tmp
				tmp.Next = nil
			} else {
				cur.Next.Next = nil
			}
		} else {
			cur.Next.Next, cur = tmp, tmp
		}
	}
}
