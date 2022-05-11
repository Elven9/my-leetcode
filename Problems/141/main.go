package main

func main() {

}

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle_Floyd(head *ListNode) bool {
	slow := head
	fast := head

	for slow != nil && fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
		if slow == fast {
			return true
		}
	}

	return false
}

func hasCycle(head *ListNode) bool {
	ptrMap := make(map[*ListNode]struct{})

	for head != nil {
		if _, ok := ptrMap[head]; ok {
			return true
		}
		ptrMap[head] = struct{}{}
		head = head.Next
	}
	return false
}
