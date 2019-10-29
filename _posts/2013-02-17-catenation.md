---
layout: post
title: "Catenation"
description: ""
category: Programs
tags: []
---
{% include JB/setup %}

	cat `find . -name "*.go"`

Meaning: find all go files in current dir including subdirs, and cat them all.