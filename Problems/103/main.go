package main

import (
	"container/list"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {

}

func zigzagLevelOrder(root *TreeNode) [][]int {
	res := make([][]int, 0)
	if root == nil {
		return res
	}

	// Dequeue structure for alternating level order traversal
	dequeueToRight := list.New()
	dequeueToLeft := list.New()
	order := byte(0)

	dequeueToRight.PushBack(root)

	for dequeueToRight.Len() != 0 || dequeueToLeft.Len() != 0 {
		layerRes := make([]int, 0)
		if order == 0 {
			// to Right
			for dequeueToRight.Len() != 0 {
				node := dequeueToRight.Remove(dequeueToRight.Front()).(*TreeNode)

				layerRes = append(layerRes, node.Val)

				if node.Left != nil {
					dequeueToLeft.PushBack(node.Left)
				}
				if node.Right != nil {
					dequeueToLeft.PushBack(node.Right)
				}
			}
		} else {
			// to Left
			for dequeueToLeft.Len() != 0 {
				node := dequeueToLeft.Remove(dequeueToLeft.Back()).(*TreeNode)

				layerRes = append(layerRes, node.Val)

				if node.Right != nil {
					dequeueToRight.PushFront(node.Right)
				}
				if node.Left != nil {
					dequeueToRight.PushFront(node.Left)
				}
			}
		}
		res = append(res, layerRes)
		order ^= 1
	}

	return res
}
