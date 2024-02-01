package main

func main() {}

func isSubsequence(s string, t string) bool {
	// Naive solution, scan through target (t), check if s is subsequence of t
	// Time complexity: O(n), space complexity: O(1)
	if len(s) == 0 {
		return true
	}

	si := 0
	for i := 0; i < len(t); i++ {
		if s[si] == t[i] {
			si++
		}
		if si == len(s) {
			break
		}
	}
	return si == len(s)
}
