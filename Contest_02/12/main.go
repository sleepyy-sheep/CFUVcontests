func fill(maze [][]int) {

	for row := 0; row < len(maze); row++ {
		for col := 0; col < len(maze[0]); col++ {
	 
			up := false
			left := false
			right := false
			down := false

			cell := maze[row][col]
			if cell == -1 {
				if row-1 >= 0 {
					if maze[row-1][col] != -1 {
						maze[row-1][col]++
						
					}
					up = true

				}
				if row+1 <= len(maze)-1 {
					if maze[row+1][col] != -1 {
						maze[row+1][col]++
						 
					}
					down = true
				}
				if col-1 >= 0 {
					if maze[row][col-1] != -1 {
						maze[row][col-1]++
						
					}
					left = true
				}
				if col+1 <= len(maze[row])-1 {
					if maze[row][col+1] != -1 {
						maze[row][col+1]++
					}
					right = true
				}

				if up && left {
					if maze[row-1][col-1] != -1 {
						maze[row-1][col-1]++
					}
				}

				if up && right {
					if maze[row-1][col+1] != -1 {
						maze[row-1][col+1]++
					}

				}
				if down && left {
					if maze[row+1][col-1] != -1 {
						maze[row+1][col-1]++
					}

				}
				if down && right {
					if maze[row+1][col+1] != -1 {
						maze[row+1][col+1]++
					}

				}
				 

			}
		 

		}
	}
 
}
