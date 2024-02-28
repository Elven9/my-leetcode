package main

func main() {}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Ans struct {
	Res   int
	Layer int
}

func findBottomLeftValue(root *TreeNode) int {
	ans := &Ans{Res: 0, Layer: -1}
	dfs(root, 0, ans)
	return ans.Res
}

func dfs(root *TreeNode, layer int, ans *Ans) {
	if root == nil {
		return
	}

	if layer > ans.Layer {
		ans.Layer = layer
		ans.Res = root.Val
	}
	dfs(root.Left, layer+1, ans)
	dfs(root.Right, layer+1, ans)
}
