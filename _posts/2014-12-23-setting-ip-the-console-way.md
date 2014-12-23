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