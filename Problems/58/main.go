package main

func main() {}

func lengthOfLastWord(s string) int {
	ed := len(s)
	// Find ed
	for ed-1 >= 0 {
		if s[ed-1] != ' ' {
			break
		}
		ed--
	}
	st := ed - 1
	// Find st
	for st-1 >= 0 {
		if s[st-1] == ' ' {
			break
		}
		st--
	}

	return len(s[st:ed])
}
