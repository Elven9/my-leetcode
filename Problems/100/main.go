package main

import "container/list"

func main() {
	isSameTree(nil, nil)
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}

func isSameTreeStack(p *TreeNode, q *TreeNode) bool {
	ps, qs := list.New(), list.New()
	ps.PushBack(p)
	qs.PushBack(q)

	for ps.Len() != 0 {
		pn, qn := ps.Remove(ps.Back()).(*TreeNode), qs.Remove(qs.Back()).(*TreeNode)
		if pn == nil || qn == nil {
			if pn != qn {
				return false
			} else {
				continue
			}
		}

		if pn.Val != qn.Val {
			return false
		}

		ps.PushBack(pn.Left)
		ps.PushBack(pn.Right)
		qs.PushBack(qn.Left)
		qs.PushBack(qn.Right)
	}

	return true
}
