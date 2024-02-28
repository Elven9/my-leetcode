package ds

type IntStack struct {
	sp  int
	mem []int
}

func (s *IntStack) Init(size int) {
	s.mem = make([]int, size)
	s.sp = -1
}

func (s *IntStack) Empty() bool {
	return s.sp == -1
}

func (s *IntStack) Push(val int) {
	// No dummyproof for reducing redundant check < size
	s.sp++
	s.mem[s.sp] = val
}

func (s *IntStack) Pop() int {
	// No dummyproof for reducing redundant check > 0
	s.sp--
	return s.mem[s.sp+1]
}

func (s *IntStack) Size() int {
	return s.sp + 1
}
