package main

import "fmt"

func main() {
	s := multipleSumBelow(1000)

	fmt.Println(s)
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
