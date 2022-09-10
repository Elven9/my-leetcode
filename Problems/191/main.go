package main

func main() {

}

func hammingWeight(num uint32) int {
	res := 0
	for i := 0; i < 32; i++ {
		if num&0x1 == 0x1 {
			res += 1
		}
		num >>= 1
	}
	return res
}
