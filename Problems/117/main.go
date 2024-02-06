package main

import "container/list"

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func main() {}

func connect(root *Node) *Node {
	// BFS ..., using node value of -101 as ending signal
	queue := list.New()
	queue.PushBack(root)

	for queue.Len() != 0 {
		n := queue.Len()

		cur := queue.Front()
		var node *Node
		for n > 0 {
			// IMPORTANT !!
			// If the type assertion holds, the value of the expression is the value stored in x and its type is T.
			// https://go.dev/ref/spec#Type_assertions
			// if cur.Value != nil {
			if cur.Value.(*Node) != nil {
				// Update Next Pointer
				if node != nil {
					node.Next = cur.Value.(*Node)
				}
				node = cur.Value.(*Node)

				queue.PushBack(node.Left)
				queue.PushBack(node.Right)
			}
			toRemove := cur
			cur = cur.Next()
			queue.Remove(toRemove)
			n--
		}
	}

	return root
}
