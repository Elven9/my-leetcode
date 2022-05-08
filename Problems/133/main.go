package main

import (
	"container/list"
	"fmt"
)

type Node struct {
	Val       int
	Neighbors []*Node
}

func main() {

	node1 := Node{
		Val: 1,
	}

	node2 := Node{
		Val: 2,
	}

	node3 := Node{
		Val: 3,
	}

	node4 := Node{
		Val: 4,
	}

	node1.Neighbors = append(node1.Neighbors, &node2)
	node1.Neighbors = append(node1.Neighbors, &node4)

	node2.Neighbors = append(node2.Neighbors, &node1)
	node2.Neighbors = append(node2.Neighbors, &node3)

	node3.Neighbors = append(node3.Neighbors, &node2)
	node3.Neighbors = append(node3.Neighbors, &node4)

	node4.Neighbors = append(node4.Neighbors, &node1)
	node4.Neighbors = append(node4.Neighbors, &node3)

	result := cloneGraph(&node1)

	fmt.Printf("End: %p \n", result)
}

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}

	stack := list.New()

	// New Graph
	newGraphNodes := make(map[int]*Node)
	newGraph := &Node{
		Val: node.Val,
	}
	newGraphNodes[node.Val] = newGraph

	// State Check
	visited := make(map[int]struct{})
	stack.PushBack(node)
	visited[node.Val] = struct{}{}

	for stack.Len() != 0 {
		popNode := stack.Back().Value.(*Node)
		stack.Remove(stack.Back())
		newNode := newGraphNodes[popNode.Val]

		// Check Each Neighbor
		for _, n := range popNode.Neighbors {
			var tmp *Node
			if v, ok := newGraphNodes[n.Val]; ok {
				tmp = v
			} else {
				tmp = &Node{
					Val: n.Val,
				}
				newGraphNodes[n.Val] = tmp
			}
			newNode.Neighbors = append(newNode.Neighbors, tmp)
			if _, ok := visited[n.Val]; !ok {
				visited[n.Val] = struct{}{}
				stack.PushBack(n)
			}
		}
	}
	return newGraph
}
