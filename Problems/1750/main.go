package main

func main() {}

func minimumLength(s string) int {
	st, ed := 0, len(s)-1

	for s[st] == s[ed] {
		ch, cs, ce := s[st], st, ed
		for cs+1 < ce && s[cs+1] == ch {
			cs++
		}
		for ce-1 > cs && s[ce-1] == ch {
			ce--
		}
		if cs >= ce {
			break
		}
		st = cs + 1
		ed = ce - 1
	}

	return len(s[st : ed+1])
}
