---
layout: post
title: "#1 Multiples of 3 and 5"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## Problem Description

From [ProjectEuler](http://projecteuler.net/problem=1):

> If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

## Solution #1

The most intuitive and straight solution, for me at least, is loop over and sum up the multiples after checking.

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

See? One loop, plus a branch, done.

Pretty simple, ah~~~

But ...

What about performance?
