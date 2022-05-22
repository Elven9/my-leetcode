package main

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	result := make([][]int, 0)

	var bfs func(n *TreeNode, l int, result *[][]int)
	bfs = func(n *TreeNode, l int, result *[][]int) {
		if n == nil {
			return
		}
		if len(*result) <= l {
			*result = append(*result, make([]int, 0))
		}
		(*result)[l] = append((*result)[l], n.Val)
		bfs(n.Left, l+1, result)
		bfs(n.Right, l+1, result)
	}

	bfs(root, 0, &result)
	return result
}
