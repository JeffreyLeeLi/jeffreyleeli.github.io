---
layout: post
title: "Display UTF 8 runes correctly in cmd under Windows"
description: ""
category: Programs
tags: [golang, utf-8]
---
{% include JB/setup %}

## What's wrong?

## Why is that?

## How to fix it?

To put it in the simple way: we just need to set `UTF-8` as current codepage, which can be done as:

    chcp 65001

where `65001` is the index for `UTF-8`.

## Tweaks?

It's recommended to use a proper font for corresponding codepages, for `UTF-8`, give `Consolas` a try. It gave me a lot of pleasure with its wonderfully designed appearance.

## Issues?

### XP


