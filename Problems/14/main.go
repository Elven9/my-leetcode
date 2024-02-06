package main

func main() {}

func longestCommonPrefix(strs []string) string {
	check := func(strs []string, idx int) bool {
		if len(strs[0]) == idx {
			return false
		}
		tmp := strs[0][idx]
		for i := 1; i < len(strs); i++ {
			if idx == len(strs[i]) || strs[i][idx] != tmp {
				return false
			}
		}
		return true
	}

	res := 0
	for ; res < 201; res++ {
		if !check(strs, res) {
			break
		}
	}
	return strs[0][:res]
}
