package main

func main() {}

func firstUniqChar(s string) int {
	// Data structure
	// using map is slower than traditional array
	ch := make([]int, 26)
	m := len(s)
	for i := 0; i < 26; i++ {
		ch[i] = m + 1
	}

	for i, r := range s {
		tmp := r - 'a'
		if ch[tmp] == m+1 {
			ch[tmp] = i
			continue
		}
		ch[tmp] = m
	}

	res := len(s)
	for _, v := range ch {
		if v < res {
			res = v
		}
	}
	if res == len(s) {
		return -1
	}
	return res
}

func firstUniqChar_NaiveSolution(s string) int {
	// Naive solution two scan, get character count, then scan for first unique
	// Trace: memory space only use O(1), with two scan
	//
	// For speed solution: one scan, one more character array for first index

	visited := make(map[rune]int)

	for i, r := range s {
		if _, ok := visited[r]; !ok {
			visited[r] = i
			continue
		}
		visited[r] = len(s)
	}

	// Check first occurence
	res := len(s)
	for k, v := range visited {
		if _, ok := visited[k]; !ok {
			continue
		}
		if v < res {
			res = v
		}
	}
	if res == len(s) {
		return -1
	}
	return res
}
