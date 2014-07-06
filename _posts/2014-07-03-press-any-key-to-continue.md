---
layout: post
title: "Press any key to continue..."
description: ""
category: Programs
tags: [c]
---
{% include JB/setup %}

## Background

For CLI console programs, we need some mechanims to pause execution and continue as convenient as possible.

While `scanf()` alike functions can do part of the work, it forces `Enter`.

Our `key` here is **any**.

## Solutions

### #1 pause

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

	请按任意键继续. . .

If not, you're likely be prompted the following error message:

	pause: command not found

### #2 getch

This is a secondary choice.

`main.c`

	#include <stdlib.h>
	#include <stdio.h>
	#include <conio.h>

	int main(int argc, char *argv[]) {
		printf("Press any key to continue...");
		getch();
		return EXIT_SUCCESS;
	}

Build and run as above.

Note that the application if responsible for prompt message.

Also, `conio.h` header is not mandatory on some OSes, which will cause:

	main.c:3:10: fatal error: 'conio.h' file not found
	#include <conio.h>
	         ^
	1 error generated.

### #3 posix

When there's no gun in our hand, we'll make our own.

`main.c`

	#include <stdlib.h>
	#include <stdio.h>
	#include <termios.h>
	#include <unistd.h>

	static int get_ch();

	int main(int argc, char *argv[]) {
		printf("Press any key to continue...\n");
		get_ch();
		return EXIT_SUCCESS;
	}

	static int get_ch() {
		int c;
		int fd = STDIN_FILENO;
		struct termios tm;
		struct termios tm_old;

		if (tcgetattr(fd, &tm) < 0) {
			return -1;
		}

		tm_old = tm;
		cfmakeraw(&tm);

		if (tcsetattr(fd, TCSANOW, &tm) < 0) {
			return -1;
		}

		c = fgetc(stdin);

		if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
			return -1;
		}

		return c;
	}

Build and run as above.

This is a general choice, as long as the OS is POSIX compatible.

## Choice

Which one to choose? It's in your own hand.
