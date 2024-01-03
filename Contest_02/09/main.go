import "strconv"
func isLucky(input string) bool {
	first, second := 0, 0
	for _, sym := range input[:3] {
		temp, _ := strconv.Atoi(string(sym))
		first += temp
	}
	for _, sym := range input[3:] {
		temp, _ := strconv.Atoi(string(sym))
		second += temp
	}
	return first == second
}
