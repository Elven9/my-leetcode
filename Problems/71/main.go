package main

import "strings"

func main() {}

func simplifyPath(path string) string {
	// Stack based solution
	// O(path segment)
	stack, sp := make([]string, 3000), -1

	// Split first
	segments := strings.Split(path, "/")

	for _, s := range segments {
		if len(s) == 0 || s == "." {
			continue
		}
		if s == ".." {
			if sp >= 0 {
				sp--
			}
			continue
		}
		sp++
		stack[sp] = s
	}

	// Construct Simplify Path
	return "/" + strings.Join(stack[:sp+1], "/")
}
