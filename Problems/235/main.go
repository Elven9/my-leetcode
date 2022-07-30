package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {

}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	// BST Search
	// Check which node's val is greater first
	min, max := p.Val, q.Val
	if min > max {
		min, max = max, min
	}

	// Start to Search
	cur := root
	for cur != nil {
		if (cur.Val > min && cur.Val < max) || cur.Val == min || cur.Val == max {
			return cur
		}

		if cur.Val > max {
			cur = cur.Left
		} else {
			cur = cur.Right
		}
	}

	// Error ?
	return nil
}
