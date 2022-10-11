package main

func main() {
}

func isHappy(n int) bool {
	// Approximation
	// 這種題目，我會比較傾向用近似法去處理，而非找到一個可以完整確定的演算法
	// 結果 100 Cycle 就可以解決這題了 XD

	// 當然 我猜這個東西會有 Cycle，所以可能可以用 Cycle Detection 的方法來解決
	slow, fast := n, n

	for {
		slow = compute(slow)
		fast = compute(fast)
		fast = compute(fast)
		if fast == 1 {
			return true
		}
		if slow == fast {
			return false
		}
	}
}

func compute(n int) int {
	tmp := 0

	for n > 0 {
		next := n % 10
		tmp += next * next
		n /= 10
	}

	return tmp
}
