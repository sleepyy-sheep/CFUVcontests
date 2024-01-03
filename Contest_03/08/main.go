package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

func main() {
 var n int
 fmt.Scan(&n)

 scanner := bufio.NewScanner(os.Stdin)
 scanner.Scan()
 numStr := strings.Fields(scanner.Text())

 ans := 0
 for _, str := range numStr {
  num, _ := strconv.Atoi(str)
  ans ^= num
 }

 fmt.Println(ans)
}
