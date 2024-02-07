package main

func main() {}

func isIsomorphic(s string, t string) bool {
	// Naive solution: scan first and check mapping between s and t
	//
	// Time Complexity: O(n), Space Complexity: O(1), with small charset
	mapping := make(map[rune]rune)
	hasBind := make(map[rune]bool)

	for i, r := range s {
		tmp := rune(t[i])
		bind, ok := mapping[r]
		if !ok && !hasBind[tmp] {
			mapping[r] = tmp
			hasBind[tmp] = true
			continue
		}

		if !ok || bind != tmp {
			return false
		}
	}

	return true
}
