package main
import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	var bukvi string

	for n > 0 {
		if n%26 == 0 {
			bukvi = string (65+(n-1)%26) + bukvi
			n /= 27
			continue
		}
		bukvi = string (64+n%26) + bukvi
		n /= 26
	}
	fmt.Println(bukvi)
}
