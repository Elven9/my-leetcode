package main

import "fmt"

func main() {
	m := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	rotate(m)
	fmt.Println(m)
}

func rotate(matrix [][]int) {
	// Transpose the Matrix first
	// Flip matrix row-wise
	//
	// Think the process as it is a real image
	m := len(matrix)
	n := len(matrix[0])

	// Transpose
	for i := 0; i < m; i++ {
		for j := 0; j < i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	// Flip Row
	for i := 0; i < m; i++ {
		for j := 0; j < n/2; j++ {
			matrix[i][j], matrix[i][n-j-1] = matrix[i][n-j-1], matrix[i][j]
		}
	}
}
