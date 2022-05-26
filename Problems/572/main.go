package main

import (
	"strconv"
	"strings"
)

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	// Preorder & In-Order
	fullTreePre := preorder(root)
	fullTreeIn := inorder(root)

	subTreePre := preorder(subRoot)
	subTreeIn := inorder(subRoot)

	return strings.Contains(fullTreePre, subTreePre) && strings.Contains(fullTreeIn, subTreeIn)
}

func preorder(root *TreeNode) string {
	// Recursive version and directly string concatnation
	if root == nil {
		return "N"
	}

	result := ""
	result += strconv.Itoa(root.Val)
	result += "|" + preorder(root.Left)
	result += "|" + preorder(root.Right)

	return result
}

func inorder(root *TreeNode) string {
	// Recursive version and directly string concatnation
	if root == nil {
		return "N"
	}

	result := ""
	result += inorder(root.Left)
	result += "|" + strconv.Itoa(root.Val)
	result += "|" + inorder(root.Right)

	return result
}
