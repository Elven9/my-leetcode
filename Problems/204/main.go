package main

func main() {}

//

func countPrimes(n int) int {
	// Create a Table
	primeTable := make([]bool, n)
	res := 0

	for num := 2; num < n; num++ {
		if !primeTable[num] {
			primeTable[num] = true
			res++
			for i := 2; i*num < n; i++ {
				primeTable[i*num] = true
			}
		}
	}

	return res
}
