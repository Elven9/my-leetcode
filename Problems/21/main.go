package main

func main() {

}

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}

	if list2 == nil {
		return list1
	}

	var nList *ListNode
	var cur *ListNode

	if list1.Val < list2.Val {
		nList, list1 = list1, list1.Next
	} else {
		nList, list2 = list2, list2.Next
	}

	cur = nList

	for list1 != nil || list2 != nil {
		if list1 == nil {
			cur.Next, list2 = list2, list2.Next
			cur = cur.Next
			continue
		}

		if list2 == nil {
			cur.Next, list1 = list1, list1.Next
			cur = cur.Next
			continue
		}

		if list1.Val < list2.Val {
			cur.Next, list1 = list1, list1.Next
		} else {
			cur.Next, list2 = list2, list2.Next
		}

		cur = cur.Next
	}

	return nList
}
