---
layout: post
title: "Login Raspberry Pi Remotely via UART Console"
description: ""
category: Toys
tags: [raspberry pi]
---
{% include JB/setup %}

## Prerequisite

I assume that you've had your baby pi configured in both hardware connections and operation system in sd card, and you can boot up and login correctly.

From there, we reduce hardware, leaving only two hardware connections to your computer:

1. USB cable: supply power
1. UART cable: interaction

Remark: a UART to USB converter may be needed if your computer is not equipped with COM interface, as in my case.

## UART

There are two rows of GPIO pins in pi's corner, near to the SD Card slot.

The pins we concerned are as following:

- Pin  6: GND
- Pin  8: Rx
- Pin 10: Tx

Which are **in order** connected to pins of converter:

- GND
- Tx
- Rx

Pay special attention to **Rx -> Tx** and **Tx -> Rx** connections.

## CoolTerm

[CoolTerm](http://freeware.the-meiers.org/) is a cross-platform solution for UART communication, which is the best one as far as I know, at least until now, ever since the minute I had my hands on it.

The UART parameters for Raspberry Pi are:

    - Baud Rate   : 115200 bps
    - Data Bits   : 8
    - Parity      : None
    - Stop Bits   : 1
    - Flow Control: No

If you prefer, you can set `CR` to emulate `Enter` key.

## Wrap up

Now that everything is ready, let's make chip hot.

If nothing goes wrong, you should be prompted with following console:

    Arch Linux 3.10.38-1-ARCH (ttyAMA0)

    alarmpi login:

By default, the only user in `Arch Linux Arm` is the most powerful `root` with password as the same. So let login:

    Welcome to Arch Linux ARM

         Website: http://archlinuxarm.org
           Forum: http://archlinuxarm.org/forum
             IRC: #archlinux-arm on irc.Freenode.net

    Last login: Wed Dec 31 17:00:26 on ttyAMA0
    [root@alarmpi ~]# ls /
    bin   dev  home  lost+found  opt   root  sbin  sys  usr
    boot  etc  lib. mnt.     proc  run. srv   tmp  var
    [root@alarmpi ~]# 

Hooary!

Keep fingering it, of course, I mean the keyboard.
