package main

func main() {}

func isValidSudoku(board [][]byte) bool {
	// Naive Solution: Scan Row, Scan Column, and Scan Three by Three Square with
	// Hashmap

	digitMap := make(map[byte]bool)

	// Chekc Each Row
	for row := 0; row < 9; row++ {
		// Reset
		for i := 1; i <= 9; i++ {
			digitMap[byte('0'+i)] = false
		}

		// Check
		for col := 0; col < 9; col++ {
			b := board[row][col]
			if b != '.' && digitMap[b] {
				return false
			}
			digitMap[board[row][col]] = true
		}
	}

	// Check Each Column
	for col := 0; col < 9; col++ {
		// Reset
		for i := 1; i <= 9; i++ {
			digitMap[byte('0'+i)] = false
		}

		// Check
		for row := 0; row < 9; row++ {
			b := board[row][col]
			if b != '.' && digitMap[b] {
				return false
			}
			digitMap[board[row][col]] = true
		}
	}

	// Check 3x3 board
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Reset
			for i := 1; i <= 9; i++ {
				digitMap[byte('0'+i)] = false
			}

			for row := i * 3; row < (i+1)*3; row++ {
				for col := j * 3; col < (j+1)*3; col++ {
					b := board[row][col]
					if b != '.' && digitMap[b] {
						return false
					}
					digitMap[board[row][col]] = true
				}
			}
		}
	}

	return true
}
