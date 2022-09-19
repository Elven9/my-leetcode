package main

import (
	"strconv"
)

func maximum69Number(num int) int {
	nstr := strconv.Itoa(num)

	for i, c := range nstr {
		if c == '6' {
			res := nstr[:i] + string('9')
			if i != len(nstr) {
				res += nstr[i+1:]
			}
			n, _ := strconv.Atoi(res)
			return n
		}
	}

	return num
}
