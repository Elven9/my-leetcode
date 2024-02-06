package main

import "strings"

func main() {}

func reverseWords(s string) string {
	// Scan from the end, construct final string
	//
	// I don't even know strings.Fields .... XD
	res := make([]string, 0)

	for i := len(s); i > 0; {
		if s[i-1] != ' ' {
			ed := i
			for i-1 >= 0 && s[i-1] != ' ' {
				i--
			}
			res = append(res, s[i:ed])
			continue
		}
		i--
	}

	return strings.Join(res, " ")
}
