package main

import "fmt"

func main() {
	wordBreak := wordBreak_bottomupDP

	fmt.Println(wordBreak("leetcode", []string{"leet", "code"}))
	fmt.Println(wordBreak("applepenapple", []string{"apple", "pen"}))
	fmt.Println(wordBreak("catsandog", []string{"cats", "dog", "sand", "and", "cat"}))
	fmt.Println(wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", []string{"a", "aa"}))
	fmt.Println(wordBreak("catsandogcat", []string{"cats", "dog", "sand", "and", "cat", "an"}))
}

func wordBreak_bottomupDP(s string, wordDict []string) bool {
	// O(n^2)
	// O(n)

	wordDictMap := make(map[string]struct{})
	for _, w := range wordDict {
		wordDictMap[w] = struct{}{}
	}

	solTable := make(map[int]bool)
	solTable[len(s)] = true

	// Construct Table
	for i := len(s) - 1; i >= 0; i-- {
		subStr := s[i:]
		tmp := false

		for j := 1; j <= len(subStr); j++ {
			if _, ok := wordDictMap[subStr[:j]]; ok && solTable[i+j] {
				tmp = true
				break
			}
		}
		solTable[i] = tmp
	}

	return solTable[0]
}

func wordBreak_recur_toDP(s string, wordDict []string) bool {
	// 這是一題最基本的 DP，就是建表的概念
	wordDictMap := make(map[string]struct{})
	for _, w := range wordDict {
		wordDictMap[w] = struct{}{}
	}

	solTable := make(map[int]bool)

	return dprecursive_impl(s, wordDictMap, 0, solTable)
}

func dprecursive_impl(s string, wordDict map[string]struct{}, suffixIdx int, solTable map[int]bool) bool {
	if len(s) == 0 {
		return true
	}

	if v, ok := solTable[suffixIdx]; ok {
		return v
	}

	result := false

	for i := 1; i <= len(s); i++ {
		if _, ok := wordDict[s[:i]]; ok && dprecursive_impl(s[i:], wordDict, suffixIdx+i, solTable) {
			result = true
			break
		}
	}

	solTable[suffixIdx] = result
	return result
}

func wordBreak_recursive_2(s string, wordDict []string) bool {

	// Preprocessing
	wordDictMap := make(map[string]struct{})
	for _, w := range wordDict {
		wordDictMap[w] = struct{}{}
	}

	return recursive_impl(s, wordDictMap)
}

func recursive_impl(s string, wordDict map[string]struct{}) bool {
	if len(s) == 0 {
		return true
	}

	for i := 1; i <= len(s); i++ {
		if _, ok := wordDict[s[:i]]; ok && recursive_impl(s[i:], wordDict) {
			return true
		}
	}
	return false
}

func wordBreak_recursive(s string, wordDict []string) bool {
	// TLE Definitely, But it will work I thinks
	if len(s) == 0 {
		return true
	} else {
		result := false
		for _, word := range wordDict {
			if len(s) >= len(word) && s[:len(word)] == word {
				result = result || wordBreak_recursive(s[len(word):], wordDict)
			}
		}
		return result
	}
}
