package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {

	root := &TreeNode{
		Val: 5,
		Left: &TreeNode{
			Val: 3,
			Left: &TreeNode{
				Val: 2,
				Left: &TreeNode{
					Val: 1,
				},
			},
			Right: &TreeNode{
				Val: 4,
			},
		},
		Right: &TreeNode{
			Val: 6,
		},
	}

	fmt.Println(kthSmallest(root, 3))
}

func kthSmallest(root *TreeNode, k int) int {
	// Inorder Solution
	// O(n) Time Complexity
	result := -1
	inorder(root, &k, &result)

	return result
}

func inorder(root *TreeNode, k *int, res *int) {
	if *res != -1 {
		return
	}
	if root.Left != nil {
		inorder(root.Left, k, res)
	}
	*k = *k - 1
	if *k == 0 {
		*res = root.Val
	}
	if root.Right != nil {
		inorder(root.Right, k, res)
	}
}
