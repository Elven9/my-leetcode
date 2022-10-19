package main

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func main() {

}

func connect(root *Node) *Node {
	// BFS, Which takes O(2^logk) space
	// use next bfs
	if root == nil {
		return root
	}

	leftest := root
	for leftest != nil {
		cur := leftest

		for cur != nil && cur.Left != nil {
			cur.Left.Next = cur.Right
			if cur.Next != nil {
				cur.Right.Next = cur.Next.Left
			}
			cur = cur.Next
		}
		leftest = leftest.Left
	}

	return root
}
