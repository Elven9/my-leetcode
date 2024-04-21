package main

func main() {}

func validPath(n int, edges [][]int, source int, destination int) bool {
	graph := make(map[int][]int)
	for _, e := range edges {
		graph[e[0]] = append(graph[e[0]], e[1])
		graph[e[1]] = append(graph[e[1]], e[0])
	}
	visited := make([]bool, n)
	return dfs(graph, visited, source, destination)
}

func dfs(graph map[int][]int, visited []bool, node, dst int) bool {
	if node == dst {
		return true
	}
	if visited[node] {
		return false
	}
	visited[node] = true
	for _, e := range graph[node] {
		if dfs(graph, visited, e, dst) {
			return true
		}
	}
	return false
}
