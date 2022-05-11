package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {

}

func reverseList(head *ListNode) *ListNode {
	var newHead *ListNode

	for head != nil {
		head.Next, newHead, head = newHead, head, head.Next
	}

	return newHead
}
