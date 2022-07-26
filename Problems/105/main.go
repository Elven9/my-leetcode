package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	buildTree([]int{3, 9, 20, 15, 7}, []int{9, 3, 15, 20, 7})
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	// Construct with Hashmap for search optimization
	indexMap := make(map[int]int)

	// Construct Map
	for i, v := range inorder {
		indexMap[v] = i
	}

	validPreorder := 0

	return recuB(preorder, indexMap, &validPreorder, 0, len(inorder))
}

func recuB(preorder []int, inorder map[int]int, vP *int, viS int, viE int) *TreeNode {
	if *vP >= len(preorder) || inorder[preorder[*vP]] < viS || inorder[preorder[*vP]] >= viE {
		return nil
	}
	head := &TreeNode{
		Val: preorder[*vP],
	}
	*vP += 1

	head.Left = recuB(preorder, inorder, vP, viS, inorder[head.Val])
	head.Right = recuB(preorder, inorder, vP, inorder[head.Val], viE)

	return head
}
