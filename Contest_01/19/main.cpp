package main

import (
  "fmt"
  "sort"
  "strings"
)

func main() {
  var s string
  word := make(map[string]int)

  for {
    fmt.Scan(&s)
    if s == "end" {
      break
    }
    word[s]++
  }

  var result []string
  for w, count := range word {
    if count > 1 {
      result = append(result, w)
    }
  }

  sort.Strings(result)
  fmt.Println(strings.Join(result, " "))
}
