package main

import "slices"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {}

func buildTree(inorder []int, postorder []int) *TreeNode {
	// Create Tree Node
	counter := len(postorder)
	return build(inorder, postorder, &counter)
}

func build(inorder, postorder []int, cnt *int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}
	node := TreeNode{Val: postorder[len(postorder)-1]}
	center := slices.Index[[]int, int](inorder, node.Val)
	*cnt--
	node.Right = build(inorder[center+1:], postorder[:*cnt], cnt)
	node.Left = build(inorder[:center], postorder[:*cnt], cnt)
	return &node
}
