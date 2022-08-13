package main

import (
	"container/list"
)

type TrieNode struct {
	decendents  [26]*TrieNode
	isEndofNode bool

	// Optimizable
	level int
}

type WordDictionary struct {
	head *TrieNode
}

func Constructor() WordDictionary {
	return WordDictionary{
		head: &TrieNode{
			level: -1,
		},
	}
}

func (this *WordDictionary) AddWord(word string) {
	cur := this.head
	for _, r := range word {
		if cur.decendents[r-'a'] == nil {
			cur.decendents[r-'a'] = &TrieNode{
				level: cur.level + 1,
			}
		}
		cur = cur.decendents[r-'a']
	}
	cur.isEndofNode = true
}

// dfs recursive version
func (this *WordDictionary) Search(word string) bool {
	return dfs(this.head, word)
}

func dfs(node *TrieNode, word string) bool {
	if len(word) == 0 {
		return node.isEndofNode
	}
	if word[0] == '.' {
		for i := 0; i < 26; i++ {
			if node.decendents[i] != nil && dfs(node.decendents[i], word[1:]) {
				return true
			}
		}
		return false
	}

	return node.decendents[word[0]-'a'] != nil && dfs(node.decendents[word[0]-'a'], word[1:])
}

// TLE Search Version
func (this *WordDictionary) Search_TLE(word string) bool {
	if len(word) == 0 {
		return false
	}

	// Use Stack to Implement Search Target
	stack := list.New()
	stack.PushBack(this.head)

	for stack.Len() != 0 {
		target := stack.Remove(stack.Back()).(*TrieNode)
		// End of The Word
		if target.level+1 == len(word) {
			if target.isEndofNode {
				return true
			}
			continue
		}
		// Wildcard
		if word[target.level+1] == '.' {
			for i := 0; i < 26; i++ {
				if target.decendents[i] != nil {
					stack.PushBack(target.decendents[i])
				}
			}
			continue
		}
		if target.decendents[word[target.level+1]-'a'] != nil {
			stack.PushBack(target.decendents[word[target.level+1]-'a'])
		}
	}

	return false
}
