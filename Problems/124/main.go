package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	leftNode := TreeNode{
		Val:   -1,
		Left:  nil,
		Right: nil,
	}
	root := TreeNode{
		Val:   2,
		Left:  &leftNode,
		Right: nil,
	}
	fmt.Println(maxPathSum(&root))
}

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxPathSum(root *TreeNode) int {
	// Recursion Version
	maxLen := 30000 * -1000

	var dfs func(n *TreeNode, l *int) int
	dfs = func(n *TreeNode, l *int) int {
		if n == nil {
			return 0
		}
		left := max(dfs(n.Left, l), 0)
		right := max(dfs(n.Right, l), 0)

		tmp := n.Val + left + right
		if tmp > *l {
			*l = tmp
		}

		return max(n.Val+left, n.Val+right)
	}

	dfs(root, &maxLen)
	return maxLen
}

type record struct {
	N       *TreeNode
	Visited bool
}

func maxPathSumStack(root *TreeNode) int {
	// DFS, change node value, O(V+E)
	// O(V)

	// Memory Usage & Tree Structure Preservation Tradeoff
	if root == nil {
		return 0
	}
	maxLen := 30000 * -1000
	stack := list.New()
	stack.PushBack(&record{
		N:       root,
		Visited: false,
	})

	for stack.Len() != 0 {
		r := stack.Back().Value.(*record)
		if r.Visited {
			stack.Remove(stack.Back())
			// Check node as root
			// And Update greddy path max
			tmp := r.N.Val
			newLen := 0
			if r.N.Left != nil && r.N.Left.Val > 0 {
				tmp += r.N.Left.Val
				newLen = r.N.Left.Val
			}
			if r.N.Right != nil && r.N.Right.Val > 0 {
				tmp += r.N.Right.Val
				if r.N.Right.Val > newLen {
					newLen = r.N.Right.Val
				}
			}
			if tmp > maxLen {
				maxLen = tmp
			}
			r.N.Val += newLen
		} else {
			// Add New Node
			r.Visited = true
			if r.N.Left != nil {
				stack.PushBack(&record{
					N:       r.N.Left,
					Visited: false,
				})
			}
			if r.N.Right != nil {
				stack.PushBack(&record{
					N:       r.N.Right,
					Visited: false,
				})
			}
		}
	}
	return maxLen
}
