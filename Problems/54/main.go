package main

import "fmt"

func main() {
	fmt.Println(spiralOrder([][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	}))
}

func spiralOrder(matrix [][]int) []int {
	// Just like traversal
	// Dir: x: [1, 0, -1, 0]
	// 		y: [0, 1, 0, -1]
	// Visited Matrix: O(mn) -> O(1), by changing element to -101 as indication
	// of visiting
	// Time: O(mn)

	dirx := []int{1, 0, -1, 0}
	diry := []int{0, 1, 0, -1}
	curDir := 0 // %4
	m := len(matrix)
	n := len(matrix[0])

	res := make([]int, 0, m*n)
	cnt := m * n
	i := 0
	j := 0
	for cnt > 0 {
		res = append(res, matrix[i][j])
		matrix[i][j] = -101
		// Change Direction
		if i+diry[curDir] >= m || i+diry[curDir] < 0 || j+dirx[curDir] >= n || j+dirx[curDir] < 0 ||
			matrix[i+diry[curDir]][j+dirx[curDir]] == -101 {
			curDir = (curDir + 1) % 4
		}

		i += diry[curDir]
		j += dirx[curDir]
		cnt--
	}

	return res
}
