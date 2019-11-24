---
layout: post
title: "Stream online media to local file via ffmpeg"
description: ""
category: Tools
tags: [ffmpeg]
---
{% include JB/setup %}

	ffmpeg -i /path/to/online/media -c copy output.mkv

`/path/to/online/media` usually refers to an m3u8 url, and `mkv` is recommended, yet not mandadory, other options are `mp4`, `ts` etc.

# Reference

- https://stackoverflow.com/questions/32528595/ffmpeg-mp4-from-http-live-streaming-m3u8-file