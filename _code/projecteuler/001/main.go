package main

import (
	"flag"
	"fmt"
)

func main() {
	var (
		n = flag.Uint64("n", 1000, "Upper limit: not included")
	)

	flag.Parse()

	fmt.Println(multipleSumBelow(*n))
}

func multipleSumBelow(n uint64) uint64 {
	var s3, s5, s15 uint64

	s3 = seriesSumOf(3, 3, largestMultipleBelow(3, n))
	s5 = seriesSumOf(5, 5, largestMultipleBelow(5, n))

	if n > 15 {
		s15 = seriesSumOf(15, 15, largestMultipleBelow(15, n))
	}

	return s3 + s5 - s15
}

func largestMultipleBelow(x, n uint64) uint64 {
	var t uint64
	t = n - 1 // Avoid including upper limit

	return t - t%x
}

func seriesSumOf(first, diff, last uint64) uint64 {
	var num uint64
	num = (last-first)/diff + 1

	return num * (first + last) / 2
}
