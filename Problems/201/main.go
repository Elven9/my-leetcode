package main

func main() {}

func rangeBitwiseAnd(left int, right int) int {
	cnt := 0
	for left != right {
		cnt++
		left >>= 1
		right >>= 1
	}
	return left << cnt
}

func rangeBitwiseAnd_SLOW(left int, right int) int {
	res := 0
	// cnt := 0
	cnt := 1
	for left > 0 || right > 0 {
		if left == right {
			// res += int(math.Pow(2, float64(cnt))) * (left % 2)
			res += cnt * (left % 2)
		}
		// cnt++
		cnt *= 2
		left /= 2
		right /= 2
	}
	return res
}
