---
layout: post
title: "Euler #001 Multiples of 3 and 5"
description: ""
category: 
tags: []
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

Pretty simple, ah~~~

But ...

What about performance?

Save above code into `main.go`, measuring with `time`, and we get:

	$ time go run main.go
	233168
	go run main.go  0.20s user 0.04s system 95% cpu 0.251 total

Within half a sec, not so bad. As can be easily noted, duration will increase with the upper limit.

So before measuring, let's make it easier for us.

### Show me the source! Again!

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


