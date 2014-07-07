---
layout: post
title: "Make Raspberry Pi Surfing"
description: ""
category: Toys
tags: [raspberry pi]
---
{% include JB/setup %}

## How?

There is one and only one ethernet interface on pi, via which we can link it into family LAN using wire cable.

## Check

From UART console:

    [root@alarmpi ~]# ifconfig

which prints, e.g.:

Also, another command:

    [root@alarmpi ~]# ip addr

which prints:

    1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default
        link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
        inet 127.0.0.1/8 scope host lo
           valid_lft forever preferred_lft forever
    2: ifb0: <BROADCAST,NOARP> mtu 1500 qdisc noop state DOWN group default qlen 32
        link/ether 02:49:11:d4:ee:74 brd ff:ff:ff:ff:ff:ff
    3: ifb1: <BROADCAST,NOARP> mtu 1500 qdisc noop state DOWN group default qlen 32
        link/ether 76:5e:b5:8d:25:00 brd ff:ff:ff:ff:ff:ff
    4: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
        link/ether b8:27:eb:3b:aa:40 brd ff:ff:ff:ff:ff:ff
        inet 192.168.1.4/24 brd 192.168.1.255 scope global eth0
           valid_lft forever preferred_lft forever

## Ping

It's smart enough to recognize the connection, preparing corresponding drivers stand by, for network, it can be verified as:

    [root@alarmpi ~]# ping www.google.com

If you got the following, then you are good to go.

    PING www.google.com (173.194.127.210) 56(84) bytes of data.
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=3 ttl=45 time=264 ms
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=4 ttl=45 time=263 ms
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=5 ttl=45 time=267 ms
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=7 ttl=45 time=266 ms
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=9 ttl=45 time=269 ms
    64 bytes from hkg03s15-in-f18.1e100.net (173.194.127.210): icmp_seq=10 ttl=45 time=268 ms
    ^C
    --- www.google.com ping statistics ---
    10 packets transmitted, 6 received, 40% packet loss, time 9027ms
    rtt min/avg/max/mdev = 263.195/266.507/269.161/2.076 ms

Note the `^C` interruption manually, or else `-c n` of `ping` option can help, where `n` is a number.

## SSH

By default, `sshd` service is listening, so we can login remotely via `ssh` from any computer in the same LAN that can ping through:

    $ ssh root@192.168.1.4

where `192.168.1.4` is Rasperry Pi's IP in my situation, which may vary from yours.

As the saying goes:

    Where you can ssh, there's no limits.

The point here is: we are freed from UART cable.

## Upgrade

Although alarmpi in SD Card is the latest `2014-06-01` version, we will upgrade the entire system, 'coz it's a rolling distribution.

    [root@alarmpi ~]# pacman -Syu
