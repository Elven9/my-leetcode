package main

func main() {}

func plusOne(digits []int) []int {
	n := len(digits)
	res := make([]int, n+1)

	// Full Adder
	copy(res[1:], digits)
	carry := 1

	for carry > 0 {
		tmp := res[n] + carry
		res[n], carry = tmp%10, tmp/10
		n--
	}

	if res[0] == 0 {
		return res[1:]
	}
	return res
}
