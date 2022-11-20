---
layout: post
title: "Set Date & Time Manually for Guest OSes of VirtualBox"
description: ""
category: Tools
tags: [virtualbox]
---
{% include JB/setup %}

	VBoxManage setextradata "Windows 11 64bit" "VBoxInternal/Devices/VMMDev/0/Config/GetHostTimeDisabled" 1