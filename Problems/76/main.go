package main

import (
	"container/list"
	"fmt"
)

func main() {
	minWindow := minWindow_QueueOptimize

	fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
	fmt.Println(minWindow("a", "a"))
	fmt.Println(minWindow("a", "aa"))
	fmt.Println(minWindow("cabwefgewcwaefgcf", "cae"))
	fmt.Println(minWindow("abcabdebac", "cda"))
	fmt.Println(minWindow("cabefgecdaecf", "cae"))
	fmt.Println(minWindow("acbbaca", "aba"))
	fmt.Println(minWindow("aaflslflsldkalskaaa", "aaa"))
}

func minWindow(s string, t string) string {
	// O(m+n) (精確一點應該是 m+2n)
	rsCount := make(map[rune]int)
	for _, r := range t {
		rsCount[r]++
	}
	start, minStart, minLen, tCount := 0, 0, 100001, len(t)

	for end, er := range s {
		rsCount[er]--
		if rsCount[er] >= 0 {
			// 重點在這啊 我剛剛沒有想到要怎麼去 Check 現在的 Windows 是不是 Valid 的
			tCount--
		}

		// A Valid Windows
		// 這邊的做法，就是去找出每個 Valid 的 Window，去看他的 Size 有沒有更短
		for tCount == 0 {
			if end-start+1 < minLen {
				minLen = end - start + 1
				minStart = start
			}
			rsCount[rune(s[start])]++
			if rsCount[rune(s[start])] > 0 {
				tCount++
			}
			start++
		}
	}
	if minLen == 100001 {
		minLen = 0
	}
	return s[minStart : minStart+minLen]
}

type RInfo struct {
	R rune
	I int
}

func minWindow_QueueOptimize(s string, t string) string {
	// O(m+n)

	// Candidate Char Count
	candMap := make(map[rune]struct{})
	candCount := make(map[rune]int)
	for _, r := range t {
		candMap[r] = struct{}{}
		candCount[r] += 1
	}

	minStart, minLen, validC := 0, 100001, len(t)
	subStrQueue := list.New()

	for i, r := range s {
		// Add New Candidate
		if _, ok := candMap[r]; ok {
			subStrQueue.PushBack(RInfo{r, i})
			candCount[r]--
			if candCount[r] >= 0 {
				validC--
			}
		} else {
			continue
		}

		// Shrink Left Size
		for validC == 0 {
			f := subStrQueue.Front().Value.(RInfo)
			b := subStrQueue.Back().Value.(RInfo)

			if b.I-f.I+1 < minLen {
				minStart = f.I
				minLen = b.I - f.I + 1
			}

			subStrQueue.Remove(subStrQueue.Front())
			candCount[f.R]++
			if candCount[f.R] > 0 {
				validC++
			}
		}
		// fmt.Println(string(r), s[subStrQueue.Front().Value.(RInfo).I:subStrQueue.Back().Value.(RInfo).I+1])
	}

	if minLen == 100001 {
		minLen = 0
	}
	return s[minStart : minStart+minLen]
}
