package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	return root == nil || isSym(root.Left, root.Right)
}

func isSym(node1 *TreeNode, node2 *TreeNode) bool {
	if node1 == nil && node2 == nil {
		return true
	} else if node1 == nil || node2 == nil {
		return false
	} else {
		return node1.Val == node2.Val && isSym(node1.Left, node2.Right) && isSym(node1.Right, node2.Left)
	}
}

// Iterative version can be accomplish by two seperate stack for mirror traversal
