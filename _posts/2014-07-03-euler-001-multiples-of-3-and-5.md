---
layout: post
title: "Euler #001 Multiples of 3 and 5"
description: ""
category: Programs
tags: [euler]
---
{% include JB/setup %}

## Problem Description

From [Project Euler #001](http://projecteuler.net/problem=1):

> If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

## Answer

	233168

## Solution #1

The most intuitive and straight solution, for me at least, is loop over and sum up the multiples after checking.

### Show me the source!

`main.go`

	package main

	import "fmt"

	func main() {
		s := 0

		for i := 0; i < 1000; i++ {
			if i%3 == 0 || i%5 == 0 {
				s += i
			}
		}

		fmt.Println(s)
	}

### Is this the end?

See? One loop, plus a branch, done.

Save above code into `main.go`, and run:

	$ go run main.go
	233168

Got the right answer. Pretty simple, ah~

But that's it?

### What about performance?

Measure it with `time`:

	$ time go run main.go
	233168
	go run main.go  0.20s user 0.04s system 95% cpu 0.251 total

Within half a sec, not so bad.

As can be easily noted, duration will increase with the upper limit.

Before measuring furtherly, let's make the work easier.

### Show me the source! Again!

`main.go`

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

We extracted a helper func and add a flag, now we can do our craft:

### Benchmark with loop

	$ time go run main.go -n=10
	23
	go run main.go -n=10  0.22s user 0.05s system 95% cpu 0.278 total

	$ time go run main.go -n=100
	2318
	go run main.go -n=100  0.23s user 0.05s system 95% cpu 0.289 total

	$ time go run main.go -n=1000
	233168
	go run main.go -n=1000  0.21s user 0.05s system 97% cpu 0.269 total

	$ time go run main.go -n=10000
	23331668
	go run main.go -n=10000  0.20s user 0.05s system 96% cpu 0.261 total

	$ time go run main.go -n=100000
	2333316668
	go run main.go -n=100000  0.21s user 0.05s system 96% cpu 0.267 total

	$ time go run main.go -n=1000000
	233333166668
	go run main.go -n=1000000  0.21s user 0.05s system 95% cpu 0.269 total

	$ time go run main.go -n=10000000
	23333331666668
	go run main.go -n=10000000  0.25s user 0.05s system 96% cpu 0.310 total

	$ time go run main.go -n=100000000
	2333333316666668
	go run main.go -n=100000000  0.48s user 0.05s system 97% cpu 0.541 total

	$ time go run main.go -n=1000000000
	233333333166666668
	go run main.go -n=1000000000  2.88s user 0.05s system 99% cpu 2.939 total

	$ time go run main.go -n=10000000000
	4886589257957115052
	go run main.go -n=10000000000  26.97s user 0.08s system 100% cpu 27.046 total

See the last one? Nearly half a minute! Unacceptable for ambitious us.

What if the limit goes even higher?

We need a solution that is the best in constant time consuming.

## Solution 2

### Some math

We need some math from senior high: Series. With regularities in peculiar:

	1, 2, 3, 4, 5, 6, 7, 8, 9, ...
	3, 6, 9, ...
	5, 10, ...

That's the clue! We know how to calculate the sum, given First Item, Common Difference and one of following:

1. Num
1. Last Item

The equation SEEMS to be:

	SumOfMultiple(3) + SumOfMultiple(5)

But there's one big fault:

	CommonMultipleOf(3, 5) are counted twice

We need substract that from the final result.

### Code implementation

So put it in code:

`main.go`

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
		s3 := seriesSumOf(3, 3, largestMultipleBelow(3, n))
		s5 := seriesSumOf(5, 5, largestMultipleBelow(5, n))
		s15 := seriesSumOf(15, 15, largestMultipleBelow(15, n))

		return s3 + s5 - s15
	}

	func largestMultipleBelow(x, n int) int {
		t := n - 1 // Avoid including upper limit
		return t - t%x
	}

	func seriesSumOf(first, diff, last int) int {
		num := (last-first)/diff + 1
		return num * (first + last) / 2
	}

Note that we removed `for` loop.

### Benchmark without loop

	$ time go run main.go -n=10
	23
	go run main.go -n=10  0.21s user 0.05s system 95% cpu 0.266 total

	$ time go run main.go -n=100
	2318
	go run main.go -n=100  0.21s user 0.05s system 95% cpu 0.266 total

	$ time go run main.go -n=1000
	233168
	go run main.go -n=1000  0.21s user 0.05s system 95% cpu 0.268 total

	$ time go run main.go -n=10000
	23331668
	go run main.go -n=10000  0.21s user 0.05s system 96% cpu 0.264 total

	$ time go run main.go -n=100000
	2333316668
	go run main.go -n=100000  0.21s user 0.05s system 95% cpu 0.268 total

	$ time go run main.go -n=1000000
	233333166668
	go run main.go -n=1000000  0.21s user 0.05s system 96% cpu 0.263 total

	$ time go run main.go -n=10000000
	23333331666668
	go run main.go -n=10000000  0.21s user 0.05s system 96% cpu 0.269 total

	$ time go run main.go -n=100000000
	2333333316666668
	go run main.go -n=100000000  0.21s user 0.05s system 96% cpu 0.270 total

	$ time go run main.go -n=1000000000
	233333333166666668
	go run main.go -n=1000000000  0.22s user 0.05s system 95% cpu 0.276 total

	$ time go run main.go -n=10000000000
	-4336782778897660756
	go run main.go -n=10000000000  0.21s user 0.05s system 96% cpu 0.265 total

### Hoary

Yeah~

Constantant time!

Perfect?

Almost. Not yet: number overflow and odd when `n` is too big.

### Final

Use `uint64` instead.

So let's fix it.

`main.go`

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

See the result.

	$ time go run main.go -n=10000000000
	4886589257957115052
	go run main.go -n=10000000000  0.21s user 0.04s system 95% cpu 0.268 total

	$ time go run main.go -n=100000000000
	9043580029263163052
	go run main.go -n=100000000000  0.22s user 0.05s system 97% cpu 0.284 total

That's it!
