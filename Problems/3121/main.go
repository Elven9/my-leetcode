package main

func main() {}

func numberOfSpecialChars(word string) int {
	ans := 0
	idx := make(map[rune]int)

	for i, r := range word {
		if _, ok := idx[r]; r < 'a' && !ok {
			idx[r] = i
			continue
		}
		if r >= 'a' {
			idx[r] = i
		}

	}
	// Check
	for r := 'a'; r <= 'z'; r++ {
		_, ok1 := idx[r]
		_, ok2 := idx[r-'a'+'A']
		if !ok1 || !ok2 {
			continue
		}
		if idx[r] < idx[r-'a'+'A'] {
			ans++
		}
	}
	return ans
}
