package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {

}

func isValidBST(root *TreeNode) bool {
	// Unique Node
	// Preorder traversal to check subtree

	if root == nil {
		return true
	}

	result, _, _ := vTree(root)
	return result
}

//nolint:ineffassign
func vTree(root *TreeNode) (bool, int, int) {
	// isOk, min, max
	// root is not allowed nil
	result, ok := true, true
	lmin, lmax, rmin, rmax := 0, 0, 0, 0
	if root.Left != nil {
		ok, lmin, lmax = vTree(root.Left)
		result = result && ok && lmax < root.Val
	}

	if result && root.Right != nil {
		ok, rmin, rmax = vTree(root.Right)
		result = result && ok && rmin > root.Val
	}

	return result, lmin, rmax
}
