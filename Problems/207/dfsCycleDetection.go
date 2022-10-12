package main

type Node struct {
	Val           int
	Visited, Done bool

	Next []*Node
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	// Goal
	//
	// Dependency Graph, a Forest
	//
	// DFS on each unvisited node, for cycle detection

	// Spec
	//
	// - Implement a direct graph
	//      - linked node: O(N+E)
	// - Implement Recursive DFS

	// Constrcut Graph
	graph := make([]*Node, numCourses)
	for i := 0; i < numCourses; i++ {
		graph[i] = &Node{
			Val: i,

			Next: make([]*Node, 0),
		}
	}

	for _, v := range prerequisites {
		graph[v[1]].Next = append(graph[v[1]].Next, graph[v[0]])
	}

	// Whole Graph to Cycle Detection
	for _, n := range graph {
		if !n.Done && cycleDetect(n) {
			return false
		}
	}
	return true
}

func cycleDetect(n *Node) bool {
	if n.Visited {
		return true
	}
	if n.Done {
		return false
	}
	n.Visited = true
	n.Done = true
	res := false
	for _, next := range n.Next {
		res = res || cycleDetect(next)
	}
	n.Visited = false

	return res
}
