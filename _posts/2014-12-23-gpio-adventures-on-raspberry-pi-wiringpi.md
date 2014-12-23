---
layout: post
title: "GPIO Adventures on Raspberry Pi #wiringPi"
description: ""
category: 
tags: []
---
{% include JB/setup %}

## Linking Error

    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_write_byte'
    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_read_byte'
    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_write_byte_data'
    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_write_word_data'
    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_read_word_data'
    /usr/lib/gcc/arm-linux-gnueabihf/4.6/../../../libwiringPi.so: undefined reference to `i2c_smbus_read_byte_data'
    collect2: ld returned 1 exit status

## Dependencies

After googling, the reasons are locked: `libi2c-dev`, `i2c-tools` and `python-smbus` and can be installed as following:

    sudo apt-get install libi2c-dev python-smbus

As can be seen `i2c-tools` is resolved and installed automatically.

## Rebuild

Rebuild is necessary, meaning uninstalling and cleaning before making and installing again.

## `gpio`

This time the `gpio` utility is usable.

    gpio -V

    gpio readall
