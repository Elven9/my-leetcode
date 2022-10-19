package main

type Node struct {
	Val  int
	Preq []*Node

	// For traversal use
	Visited bool
	Done    bool
}

func main() {}

func findOrder(numCourses int, prerequisites [][]int) []int {
	if numCourses == 1 {
		return []int{0}
	}

	// Construct Graph
	graph := make([]*Node, numCourses)
	for idx := 0; idx < numCourses; idx++ {
		graph[idx] = &Node{
			Val: idx,
		}
	}

	// Construct Dependency
	for _, prerequisite := range prerequisites {
		graph[prerequisite[0]].Preq = append(graph[prerequisite[0]].Preq, graph[prerequisite[1]])
	}

	// Cycle Detect DFS and Record Sequence
	res := make([]int, 0)
	for _, node := range graph {
		if !node.Done {
			subRes, flag := cycleDetectAndRecord(node)
			if flag {
				return []int{}
			}
			res = append(res, subRes...)
		}
	}

	return res
}

func cycleDetectAndRecord(root *Node) ([]int, bool) {
	if root.Visited {
		return []int{}, true
	}
	if root.Done {
		return []int{}, false
	}
	root.Visited = true
	root.Done = true

	res := make([]int, 0)

	for _, preq := range root.Preq {
		tmp, flag := cycleDetectAndRecord(preq)
		if flag {
			return []int{}, flag
		} else {
			res = append(res, tmp...)
		}
	}
	root.Visited = false
	res = append(res, root.Val)

	return res, false
}
