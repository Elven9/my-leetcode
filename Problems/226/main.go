package main

import "container/list"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	// DFS, O(V+E)
	// O(V)
	if root == nil {
		return nil
	}

	stack := list.New()
	stack.PushBack(root)

	for stack.Len() != 0 {
		n := stack.Remove(stack.Back()).(*TreeNode)
		if n.Left != nil {
			stack.PushBack(n.Left)
		}
		if n.Right != nil {
			stack.PushBack(n.Right)
		}
		n.Left, n.Right = n.Right, n.Left
	}

	return root
}
