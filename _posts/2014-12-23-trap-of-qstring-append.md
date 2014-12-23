---
layout: post
title: "Trap of QString append"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## Background

In developing of a device remote control program, bytes are required to put in sequences according to communication protocols, defined by the manufacture.

Among those bytes, `0x00` exists. And that's where I was trapped.

## Wrong

    QString str;
    str.append(0x00);

By the end, `str` still contains nothing.

## Right

    QString str;

    char c = 0x00;
    str.append(c);

In this way, `str` has one character, representing `NUL` in ASCII table.
