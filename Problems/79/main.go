package main

import "fmt"

func main() {
	fmt.Println(exist(
		[][]byte{
			{'A', 'B', 'C', 'E'},
			{'S', 'F', 'C', 'S'},
			{'A', 'D', 'E', 'E'},
		}, "ABCCED"))
}

func exist(board [][]byte, word string) bool {
	m := len(board)
	n := len(board[0])

	visited := [6][6]bool{}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if dfs(board, visited, i, j, word, 0) {
				return true
			}
		}
	}
	return false
}

func dfs(board [][]byte, visited [6][6]bool, i int, j int, word string, wcnt int) bool {
	if word[wcnt] != board[i][j] {
		return false
	}
	if wcnt == len(word)-1 {
		return true
	}

	visited[i][j] = true
	res := false

	// up
	if i-1 >= 0 && !visited[i-1][j] {
		res = res || dfs(board, visited, i-1, j, word, wcnt+1)
	}

	// right
	if j+1 < len(board[0]) && !visited[i][j+1] {
		res = res || dfs(board, visited, i, j+1, word, wcnt+1)
	}

	// down
	if i+1 < len(board) && !visited[i+1][j] {
		res = res || dfs(board, visited, i+1, j, word, wcnt+1)
	}

	// left
	if j-1 >= 0 && !visited[i][j-1] {
		res = res || dfs(board, visited, i, j-1, word, wcnt+1)
	}

	visited[i][j] = false
	return res
}
