package main

func main() {}

// Use Trie to Help DFS on the Board
type TrieNode struct {
	Next     []*TrieNode
	HasReach bool
}

func findWords(board [][]byte, words []string) []string {
	// Build Trie
	dict := &TrieNode{
		Next: make([]*TrieNode, 26),
	}

	// Optimization
	hasVisited := make([]*TrieNode, len(words))

	for i, word := range words {
		cur := dict
		for _, c := range word {
			if cur.Next[c-'a'] == nil {
				cur.Next[c-'a'] = &TrieNode{Next: make([]*TrieNode, 26)}
			}
			cur = cur.Next[c-'a']
		}
		hasVisited[i] = cur
	}

	// Dfs on the Board
	m, n := len(board), len(board[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			dfs(board, dict, i, j)
		}
	}

	res := make([]string, 0)
	for i, n := range hasVisited {
		if n.HasReach {
			res = append(res, words[i])
		}
	}

	return res
}

func dfs(board [][]byte, trieNode *TrieNode, i, j int) {
	nc := board[i][j] - 'a'
	if board[i][j] == '#' || trieNode == nil || trieNode.Next[nc] == nil {
		return
	}

	board[i][j] = '#'
	tmp := trieNode.Next[nc]
	tmp.HasReach = true

	if i > 0 {
		dfs(board, tmp, i-1, j)
	}
	if j > 0 {
		dfs(board, tmp, i, j-1)
	}
	if i < len(board)-1 {
		dfs(board, tmp, i+1, j)
	}
	if j < len(board[0])-1 {
		dfs(board, tmp, i, j+1)
	}

	board[i][j] = nc + 'a'
}
