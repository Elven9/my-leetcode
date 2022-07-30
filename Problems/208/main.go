package main

import "fmt"

type TrieNode struct {
	decendents  [26]*TrieNode
	isEndofNode bool
}

type Trie struct {
	head *TrieNode
}

func main() {
	obj := Constructor()
	obj.Insert("apple")
	fmt.Println(obj.Search("apple"))
	fmt.Println(obj.Search("app"))
	fmt.Println(obj.StartsWith("app"))
	obj.Insert("app")
	fmt.Println(obj.Search("app"))
}

// How to Deal with Ending Node

func Constructor() Trie {
	return Trie{
		head: &TrieNode{},
	}
}

func (this *Trie) Insert(word string) {
	cur := this.head
	for _, r := range word {
		if cur.decendents[r-'a'] == nil {
			cur.decendents[r-'a'] = &TrieNode{}
		}
		cur = cur.decendents[r-'a']
	}
	cur.isEndofNode = true
}

func (this *Trie) Search(word string) bool {
	cur := this.head
	for _, r := range word {
		if cur.decendents[r-'a'] == nil {
			return false
		}
		cur = cur.decendents[r-'a']
	}
	return cur.isEndofNode
}

func (this *Trie) StartsWith(prefix string) bool {
	cur := this.head
	for _, r := range prefix {
		if cur.decendents[r-'a'] == nil {
			return false
		}
		cur = cur.decendents[r-'a']
	}
	return true
}
