package main

import "fmt"

func main() {
	testcases := []struct {
		tasks []byte
		n     int
	}{
		{
			[]byte{'A', 'C', 'A', 'B', 'D', 'B'},
			1,
		},
	}

	for _, tc := range testcases {
		fmt.Println(leastInterval(tc.tasks, tc.n))
	}
}

func leastInterval(tasks []byte, n int) int {
	freq, maxFreq, mostFreqCnt := make([]int, 26), -1, 0
	for _, t := range tasks {
		freq[t-'A']++
	}
	for _, f := range freq {
		if f > maxFreq {
			maxFreq = f
			mostFreqCnt = 1
		} else if f == maxFreq {
			mostFreqCnt++
		}
	}
	if mostFreqCnt >= n+1 {
		return len(tasks)
	}
	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
	return len(tasks) + max(0, (maxFreq-1)*(n-mostFreqCnt+1)-len(tasks)+mostFreqCnt*maxFreq)
}
