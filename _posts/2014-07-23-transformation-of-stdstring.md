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
