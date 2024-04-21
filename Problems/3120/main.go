package main

func main() {}

func numberOfSpecialChars(word string) int {
	f := make(map[rune]int)

	for _, r := range word {
		f[r]++
	}

	ans := 0
	for k, v := range f {
		if k < 'a' && (v != 0 && f[k-'A'+'a'] != 0) {
			ans++
		}
	}
	return ans
}
