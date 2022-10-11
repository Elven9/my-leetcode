package main

func main() {

}

func solve(board [][]byte) {
	// Goal
	//
	// 只要有跟邊界上的 O 連再一起的 O 就不可以翻回 X
	// 其餘都可以翻成 X
	//
	// Brute force: DFS on each 'O' Blocks, 只要走的過程中有走到邊界，就不能翻
	// -> O(m*n * m*n), O(1)
	//
	// Solution 1:
	// 從邊界為 O 的地方開始走，有走到的就標示成 E, 最後重新塗色一次（O -> X, E -> O）
	// O(m*n * (m+n))
	//
	// Spec
	//
	// - Traverse 方法：
	//      - up, right, down, left，走過的地方直接標成 E，用 Recur 的走法
	// - Scanning
	//      - O -> X
	//      - E -> O

	m, n := len(board), len(board[0])

	// Horizontal Scanning
	for j := 0; j < n; j++ {
		// Sanning i == 0, m-1
		if board[0][j] == 'O' {
			traverse(0, j, board)
		}
		if board[m-1][j] == 'O' {
			traverse(m-1, j, board)
		}
	}

	// Vertical Scanning
	for i := 0; i < m; i++ {
		// Sanning j == 0, n-1
		if board[i][0] == 'O' {
			traverse(i, 0, board)
		}
		if board[i][n-1] == 'O' {
			traverse(i, n-1, board)
		}
	}

	// Last Scanning
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == 'E' {
				board[i][j] = 'O'
			}
		}
	}
}

func traverse(i, j int, board [][]byte) {
	m, n := len(board), len(board[0])
	board[i][j] = 'E'
	if i-1 >= 0 && board[i-1][j] == 'O' {
		// up
		traverse(i-1, j, board)
	}
	if j+1 < n && board[i][j+1] == 'O' {
		// left
		traverse(i, j+1, board)
	}
	if i+1 < m && board[i+1][j] == 'O' {
		// down
		traverse(i+1, j, board)
	}
	if j-1 >= 0 && board[i][j-1] == 'O' {
		traverse(i, j-1, board)
	}
}
