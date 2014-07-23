---
layout: post
title: "Transformation of std::string"
description: ""
category: Programs
tags: [c++, string]
---
{% include JB/setup %}

## Why I need this?

In a small project, I need to compare a user input of type std::string with predefined commands, which are case insesnsitive. So I need to convert the string to lower case first.

## Is there a method within std::string?

Directly? Noop.

But, there's only one step forward.

Let's see.

## General algorithm API

In `algorithm` header, there is a general algorithm API: `transform`, which can help us achieve the goal.

`main.cpp`

    #include <iostream>

    #include <string>
    #include <algorithm>

    typedef int(*UnaryOperator)(int);

    static int minusOne(int x);
    static std::string transformFor(const std::string &str, UnaryOperator op);

    int main(int argc, char *argv[]) {
        UnaryOperator ops[] = {
            tolower,
            toupper,
            minusOne,
        };

        int n = sizeof(ops) / sizeof(ops[0]);

        for (int i = 1; i < argc; i++) {
            if (i > 1) {
                std::cout << std::endl;
            }

            std::string str = argv[i];
            std::cout << str;

            for (int j = 0; j < n; j++) {
                std::string t = transformFor(str, ops[j]);
                std::cout << "\t->\t" << t << std::endl;
            }
        }

        return 0;
    }

    int minusOne(int x) {
        return x - 1;
    }

    std::string transformFor(const std::string &str, UnaryOperator op) {
        std::string t = str;

        transform(str.begin(), str.end(), t.begin(), op);

        return t;
    }
