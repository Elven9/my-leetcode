package main

import (
	"container/list"
	"fmt"
)

type Class struct {
	Val        int
	Dependency []*Class

	// Khan
	InDegree int
}

func main() {
	canFinish := canFinish_khan

	fmt.Println(canFinish(2, [][]int{{1, 0}}))
	fmt.Println(canFinish(2, [][]int{{1, 0}, {0, 1}}))
	fmt.Println(canFinish(5, [][]int{{1, 4}, {2, 4}, {3, 1}, {3, 2}}))
	fmt.Println(canFinish(8, [][]int{{1, 0}, {2, 6}, {1, 7}, {6, 4}, {7, 0}, {0, 5}}))
}

func canFinish_khan(numCourses int, prerequisites [][]int) bool {
	classes := make([]*Class, numCourses)
	for i := range classes {
		classes[i] = &Class{
			Val:      i,
			InDegree: 0,
		}
	}
	for _, d := range prerequisites {
		classes[d[0]].Dependency = append(classes[d[0]].Dependency, classes[d[1]])
		classes[d[1]].InDegree += 1
	}

	queue := list.New()
	for _, c := range classes {
		if c.InDegree == 0 {
			queue.PushBack(c)
		}
	}

	visited := 0
	for queue.Len() != 0 {
		c := queue.Front().Value.(*Class)
		queue.Remove(queue.Front())
		visited += 1

		for _, d := range c.Dependency {
			d.InDegree -= 1
			if d.InDegree == 0 {
				queue.PushBack(d)
			}
		}
	}

	return visited == numCourses
}

func canFinish_cycleENode(numCourses int, prerequisites [][]int) bool {
	// DFS on each class
	// Dependency should be an tree structure for us to take the root class
	classes := make([]*Class, numCourses)
	for i := range classes {
		classes[i] = &Class{
			Val: i,
		}
	}

	// Construct Dependency
	for _, d := range prerequisites {
		classes[d[0]].Dependency = append(classes[d[0]].Dependency, classes[d[1]])
	}

	// For every class, take dfs on them check if theirs a loop
	// DFS cycle detection
	for _, c := range classes {
		tmp := dependencyDetection(c)
		if tmp {
			return false
		}
	}
	return true
}

func dependencyDetection(root *Class) bool {
	visited := make(map[int]struct{})
	pathRec := make(map[int]struct{})
	stack := list.New()

	stack.PushBack(root)
	visited[root.Val] = struct{}{}

	for stack.Len() != 0 {
		popNode := stack.Back().Value.(*Class)
		if _, ok := pathRec[popNode.Val]; ok {
			stack.Remove(stack.Back())
			delete(pathRec, popNode.Val)
			continue
		}
		pathRec[popNode.Val] = struct{}{}

		for _, d := range popNode.Dependency {
			if _, ok := pathRec[d.Val]; ok {
				return true
			}
			if _, ok := visited[d.Val]; !ok {
				visited[d.Val] = struct{}{}
				stack.PushBack(d)
			}
		}
	}
	return false
}
