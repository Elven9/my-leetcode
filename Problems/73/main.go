package main

import "fmt"

func main() {
	m := [][]int{
		{1},
		{0},
		{3},
	}
	setZeroes(m)
	fmt.Println(m)
}

func setZeroes(matrix [][]int) {
	// Space: O(1)
	m := len(matrix)
	n := len(matrix[0])

	toFlipSignRow := false
	toFlipSignCol := false

	// Scan First
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				matrix[i][0] = 0
				matrix[0][j] = 0
				if i == 0 {
					toFlipSignRow = true
				}
				if j == 0 {
					toFlipSignCol = true
				}
			}
		}
	}

	// Flip Next
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	// Flip Sign Row and Column
	if toFlipSignRow {
		for j := 0; j < n; j++ {
			matrix[0][j] = 0
		}
	}

	if toFlipSignCol {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}
}

func setZeroes_Naive(matrix [][]int) {
	// Naive Solution
	// Scan through every zeros in map first, and zero out all row and column

	tRow := make(map[int]struct{})
	tCol := make(map[int]struct{})

	m := len(matrix)
	n := len(matrix[0])

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				tRow[i] = struct{}{}
				tCol[j] = struct{}{}
			}
		}
	}

	// Zero out in place
	for k, _ := range tRow {
		for i := 0; i < n; i++ {
			matrix[k][i] = 0
		}
	}
	for k, _ := range tCol {
		for i := 0; i < m; i++ {
			matrix[i][k] = 0
		}
	}
}
