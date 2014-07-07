---
layout: post
title: "Login Raspberry Pi Remotely via UART Console"
description: ""
category: Toys
tags: [raspberry pi, golang]
---
{% include JB/setup %}

## Prerequisite

I assume that you've had your baby pi configured in both hardware connections and operation system, and you can boot up and login correctly.

From there, we reduce hardware, leaving only two hardware connections to your computer:

1. USB cable: supply power
1. UART cable: interaction

Remark: a UART to USB converter may be needed if your computer is not equipped with COM interface, as in my case.

## UART Pins

There is two rows of GPIO pins in pi's corner, near to the SD Card slot.
