---
layout: post
title: "Archlinux Essay Series: backup"
description: ""
category: 
tags: []
---
{% include JB/setup %}

You can't be too carefully. Even god don't know when the whole world would fall into pieces, like the program crashes. So it's absolutely necessary to always backup what's important, 'coz nothing is supposed to last eternally, including this sentence~:-).

Anyway, here's the habits when I touch things from time to time. Take `/etc/rc.conf` as an example for an vivid convention explanation.

At first, there's only one `/etc/rc.conf` file. One day, which will come earlier than we expect, we need to modify it, that's exactly when we create a backup in case our modification bugs, or worse, destroys the OS.

	cp /etc/rc.conf /etc/rc.conf.bak

In this way we have the chance to turn things back to the state just as before by just overwriting corrupted one with our back up.

Then when modify it, changed what we want to. After we are sure that it does what we expected, we do another back up.

	cp /etc/rc.conf /etc/rc.conf.cur

We do so because sometimes someone may accidentally overwrite our modified version. If that happens, the current version is the quick rescue, freeing the labour of typing everything again.

Note that when you have to change system configuration files, either enter `su` mode, or preceed the command with `sudo` if you have installed that utility.