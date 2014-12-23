---
layout: post
title: "Setting IP the console way"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## ifconfig

    sudo ifconfig eth0 169.254.236.58

Note that the config info is temperorily effective, it's dropped everytime the system reboots. Yet it can be put in a bash script for easy reconfigure.

## Tip

The `arp` utility command can help us to recognize device's IP easily.

### Raspberry Pi

    pi@raspberrypi ~ $ arp
    Address                  HWtype  HWaddress           Flags Mask            Iface
    169.254.236.59           ether   a8:20:66:30:90:2d   C                     eth0

### MacBook Pro

    Lizhais-MacBook-Pro:~ jeffrey$ arp -a
    ? (17.151.16.23) at (incomplete) on en0 ifscope [ethernet]
    calendar.google.com (74.125.39.100) at (incomplete) on en0 ifscope [ethernet]
    ? (169.254.236.58) at b8:27:eb:3b:aa:40 on en0 [ethernet]
    ? (224.0.0.251) at 1:0:5e:0:0:fb on en0 ifscope permanent [ethernet]