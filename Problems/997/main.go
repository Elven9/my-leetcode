package main

func main() {}

func findJudge(n int, trust [][]int) int {
	// O(N) scan, O(n) space
	notJudges, trustCnt := make([]bool, n+1), make([]uint, n+1)
	for _, t := range trust {
		notJudges[t[0]] = true
		trustCnt[t[1]]++
	}

	// Gen result
	for i := 1; i < len(notJudges); i++ {
		if !notJudges[i] && trustCnt[i] == uint(n)-1 {
			return i
		}
	}
	return -1
}
