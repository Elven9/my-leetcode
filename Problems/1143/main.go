package main

import "fmt"

func main() {

	fmt.Println(longestCommonSubsequence("abcde", "ace"))
	fmt.Println(longestCommonSubsequence("abc", "abc"))
	fmt.Println(longestCommonSubsequence("abc", "def"))
	fmt.Println(longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd"))
}

func longestCommonSubsequence(text1 string, text2 string) int {
	// DP, Typical Solution, tabulation
	// Time: O(m*n)
	// Space: O(m*n)
	n_size, m_size := len(text1)+1, len(text2)+1

	lenMap := make([][]int, n_size)
	for i := range lenMap {
		lenMap[i] = make([]int, m_size)
		lenMap[i][0] = 0
	}
	for i := range lenMap[0] {
		lenMap[0][i] = 0
	}

	for n := 1; n < n_size; n++ {
		for m := 1; m < m_size; m++ {
			if text1[n-1] == text2[m-1] {
				lenMap[n][m] = lenMap[n-1][m-1] + 1
			} else {
				lenMap[n][m] = lenMap[n-1][m]
				if lenMap[n][m-1] > lenMap[n][m] {
					lenMap[n][m] = lenMap[n][m-1]
				}
			}
		}
	}

	return lenMap[len(text1)][len(text2)]
}

func longestCommonSubsequence_notWork(text1 string, text2 string) int {
	// An alphabetic table that record each character's index
	// An sequence of currently best result
	// Time Complexity: O(n^2m)
	// Space Complexity: O(m+n)
	// Not Gonna Work. I consider only one solution space (text1).
	alphabeticTable := make(map[rune][]int)
	usedIndex := make([]int, len(text1))
	lenRecords := make([]int, len(text1))
	result := 0

	// Construct table from text2
	for i := 0; i < 26; i++ {
		alphabeticTable[rune(97+i)] = make([]int, 0)
	}
	for i, c := range text2 {
		alphabeticTable[c] = append(alphabeticTable[c], i)
	}

	// DP Start
	for idx, c := range text1 {
		lenRecords[idx] = 0
		usedIndex[idx] = -1
		if len(alphabeticTable[c]) > 0 {
			lenRecords[idx] = 1
			usedIndex[idx] = alphabeticTable[c][0]
		}
		for i := 0; i < idx; i++ {
			for _, j := range alphabeticTable[c] {
				if lenRecords[i] > 0 && j > usedIndex[i] && lenRecords[i]+1 > lenRecords[idx] {
					lenRecords[idx] = lenRecords[i] + 1
					usedIndex[idx] = j
					break
				}
			}
		}
		if lenRecords[idx] > result {
			result = lenRecords[idx]
		}
	}

	return result
}
