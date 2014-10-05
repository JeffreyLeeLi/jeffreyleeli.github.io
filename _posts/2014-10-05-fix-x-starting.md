---
layout: post
title: "Fix X starting"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## Problem

Only console users are allowed to run the X server

## Solution

`/etc/X11/Xwrapper.config`

    allowed_users=anybody|console|root
