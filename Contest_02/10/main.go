func shift(ar []int, steps int) {
	ar_0 := make([]int, len(ar))
	copy(ar_0, ar)
	if steps < 0 {
		steps = 10 - steps*(-1)%10
	}

	for index := 0; index < steps%10; index++ {
		ar[index] = ar_0[10-steps%10+index]
	}
	for index := steps % 10; index < 10; index++ {
		ar[index] = ar_0[index-steps%10]
	}

}
