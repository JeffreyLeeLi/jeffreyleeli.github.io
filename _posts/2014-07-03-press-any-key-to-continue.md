---
layout: post
title: "Press any key to continue..."
description: ""
category: 
tags: []
---
{% include JB/setup %}

## Background

For CLI console programs, we need some mechanims to pause execution and continue as convenient as possible.

While `scanf()` alike functions can do part of the work, it forces `Enter`.

Our `key` here is ***any***.

## #1 pause

This is the easiest one.

`main.c`

	#include <stdlib.h>
	#include <stdio.h>

	int main(int argc, char *argv[]) {
		system("pause");
		return EXIT_SUCCESS;
	}

Let's build and run it.

	$ gcc main.c
	$ ./a.out

But only works when `pause` utility is available, which is provided by default under Windows.

	Press any key to continue...

The `pause` command handles not only the hint message, but also i18n, e.g. on zh_CN machines:

	按任意键继续...

If not, you're likely be prompted the following error message:

	pause: command not found

## #2 getch

This is a secondory choice.

`main.c`

	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>

	int main(int argc, char *argv[]) {
		printf("Press any key to continue...");
		getch();
		return EXIT_SUCCESS;
	}

Build and run as above. Note that the application if responsible for prompt message.
