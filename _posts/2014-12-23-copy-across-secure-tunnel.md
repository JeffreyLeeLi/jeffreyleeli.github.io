---
layout: post
title: "Copy Across Secure Tunnel"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## `scp`

## Local -> Remote

    scp ./raspi_blink root@192.168.1.3:/root

## Remote -> Local

    scp root@192.168.1.3:/root/raspi_blink .
