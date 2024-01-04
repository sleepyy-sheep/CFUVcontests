type SimpleStack []rune

func NewSimpleStack() *SimpleStack {
	return &SimpleStack{}
}

func (s *SimpleStack) empty() bool {
	return len(*s) == 0
}

func (s *SimpleStack) push(r rune) {
	*s = append(*s, r)
}

func (s *SimpleStack) top() rune {
	return (*s)[len(*s)-1]
}

func (s *SimpleStack) pop() rune {
	r := s.top()
	*s = (*s)[:len(*s)-1]
	return r
}
