package main

func main() {}

func canCompleteCircuit(gas []int, cost []int) int {
	// Faster version with O(n) greedy
}

func canCompleteCircuit_slow(gas []int, cost []int) int {
	m, tg, tc := len(gas), 0, 0

	for i := 0; i < m; i++ {
		tg += gas[i]
		tc += cost[i]
	}

	if tg < tc {
		return -1
	}

	for i := 0; i < m; i++ {
		cur := i
		ga := gas[cur] - cost[cur]

		if ga < 0 {
			continue
		}
		cur++
		if cur == m {
			cur = 0
		}

		for {
			ga += gas[cur] - cost[cur]
			if ga >= 0 && cur != i {
				if cur+1 == m {
					cur = 0
				} else {
					cur++
				}
			} else {
				break
			}
		}

		if cur == i && ga >= 0 {
			return i
		}
	}

	return -1
}
