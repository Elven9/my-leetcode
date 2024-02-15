package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {}

func sumNumbers(root *TreeNode) int {
	res := 0
	dfs(root, 0, &res)
	return res
}

func dfs(root *TreeNode, sum int, res *int) {
	if root == nil {
		return
	}

	newSum := sum*10 + root.Val
	if root.Left == nil && root.Right == nil {
		*res += newSum
		return
	}
	dfs(root.Left, newSum, res)
	dfs(root.Right, newSum, res)
}
