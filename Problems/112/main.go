package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {}

func hasPathSum(root *TreeNode, targetSum int) bool {
	// Go DFS
	if root == nil {
		return false
	}

	nextTarget := targetSum - root.Val
	if root.Left == nil && root.Right == nil && nextTarget == 0 {
		return true
	}
	return hasPathSum(root.Left, nextTarget) || hasPathSum(root.Right, nextTarget)
}
