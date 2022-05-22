package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type record struct {
	N *TreeNode
	L int
}

func maxDepth(root *TreeNode) int {
	// DFS, O(V+E)
	// O(V)

	if root == nil {
		return 0
	}

	maxLen := 0
	stack := list.New()
	stack.PushBack(record{
		N: root,
		L: 1,
	})

	for stack.Len() != 0 {
		n := stack.Remove(stack.Back()).(record)

		// Left
		if n.N.Left == nil {
			if n.L > maxLen {
				maxLen = n.L
			}
		} else {
			stack.PushBack(record{
				N: n.N.Left,
				L: n.L + 1,
			})
		}

		// Right
		if n.N.Right == nil {
			if n.L > maxLen {
				maxLen = n.L
			}
		} else {
			stack.PushBack(record{
				N: n.N.Right,
				L: n.L + 1,
			})
		}
	}

	return maxLen
}
