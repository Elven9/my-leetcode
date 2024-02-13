package main

func main() {}

func firstPalindrome(words []string) string {
	// Scan and check => O(n), O(1)
	check := func(w string) bool {
		m := len(w) - 1
		limit := m / 2
		for i := 0; i < limit; i++ {
			if w[i] != w[m-i] {
				return false
			}
		}
		return true
	}
	for _, w := range words {
		if check(w) {
			return w
		}
	}
	return ""
}

func firstPalindrome_Naive(words []string) string {
	// Scan and check => O(n), O(1)
OUTER:
	for _, w := range words {
		m := len(w)
		st, ed := m/2-1, m/2
		if m%2 != 0 {
			// aba
			ed++
		}
		for st >= 0 {
			if w[st] != w[ed] {
				continue OUTER
			}
			st--
			ed++
		}
		return w
	}
	return ""
}
