package main

func reverseBits(num uint32) uint32 {
	// Reverse in O(n)
	var res uint32 = 0
	for i := 0; i < 32; i++ {
		res <<= 1
		res |= num & 0x1
		num >>= 1
	}

	return res
}
