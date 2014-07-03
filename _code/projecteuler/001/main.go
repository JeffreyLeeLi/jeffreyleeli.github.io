package main

import (
	"flag"
	"fmt"
)

func main() {
	var (
		n = flag.Int("n", 1000, "Upper limit: not included")
	)

	flag.Parse()

	fmt.Println(multipleSumBelow(*n))
}

func multipleSumBelow(n int) int {
	s := 0

	for i := 0; i < n; i++ {
		if i%3 == 0 || i%5 == 0 {
			s += i
		}
	}

	return s
}
