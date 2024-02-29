package main

import (
	"container/list"
	"math"
)

func main() {}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isEvenOddTree(root *TreeNode) bool {
	// BFS check with layer enabled
	queue := list.New()
	isEvenlayer, cnt := true, 1
	queue.PushBack(root)

	for queue.Len() != 0 {
		tmp := cnt
		cnt = 0
		last := 0
		if !isEvenlayer {
			last = math.MaxInt
		}
		for tmp > 0 {
			n := queue.Remove(queue.Front()).(*TreeNode)

			tmp--
			if n == nil {
				continue
			}
			if isEvenlayer {
				// odd, strictly increasing
				if n.Val <= last || n.Val%2 == 0 {
					return false
				}
			} else {
				// even, strictly decreasing
				if n.Val >= last || n.Val%2 == 1 {
					return false
				}
			}
			last = n.Val
			queue.PushBack(n.Left)
			queue.PushBack(n.Right)
			cnt += 2
		}
		isEvenlayer = !isEvenlayer
	}
	return true
}
