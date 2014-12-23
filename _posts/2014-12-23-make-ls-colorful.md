---
layout: post
title: "Make ls colorful"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## How

Use alias.

## Where

Depending on which shell is used and whether it's a user or system level configure.

For `bash`:

- User: ~/.bashrc
- System: /etc/profile

## MacOS

    alias ls='ls -G'

## Linux

    alias ls='ls --color=auto'
