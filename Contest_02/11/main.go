func isValidSudoku(bord [9][9]int) bool {

	res := make([]int, 10)
	for row := 0; row < 9; row++ {
		for col := 0; col < 9; col++ {
			res[bord[row][col]]++
			if res[bord[row][col]] > 1 {
				return false
			}
		}
		res = make([]int, 10)
	}

	for row := 0; row < 9; row++ {
		for col := 0; col < 9; col++ {
			res[bord[col][row]]++
			if res[bord[col][row]] > 1 {

				return false
			}
		}
		res = make([]int, 10)
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			for row := i * 3; row < 3*(i+1); row++ {
				for col := j * 3; col < 3*(j+1); col++ {
					res[bord[row][col]]++

					if res[bord[row][col]] > 1 {

						return false
					}
				}
				fmt.Println()
			}
			res = make([]int, 10)
		}
	}
	return true
}
