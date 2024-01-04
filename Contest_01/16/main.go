package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    temperatura := make([]float64, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&temperatura[i])
    }

    srtemperatura := make([]float64, n)
    srtemperatura[0] = temperatura[0]

    for i := 1; i < n-1; i++ {
        srtemperatura[i] = (temperatura[i-1] + temperatura[i] + temperatura[i+1]) / 3
    }

    srtemperatura[n-1] = temperatura[n-1]

    for _, temp := range srtemperatura {
        fmt.Printf("%.10f ", temp)
    }
}
