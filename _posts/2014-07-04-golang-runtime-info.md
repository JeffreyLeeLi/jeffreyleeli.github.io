---
layout: post
title: "Golang Runtime Info"
description: ""
category: Programs
tags: [golang]
---
{% include JB/setup %}

For golang, we can get information about runtime easily, via `runtime` pkg.

## Golang related env

We can get info about golang, e.g.

- Compiler
- OS
- Arch
- Root Dir
- Version
- ...

`runtime-info.go`

    package main

    import (
        "fmt"
        "runtime"
    )

    func main() {
        fmt.Println(runtime.Compiler)

        fmt.Println(runtime.GOOS)
        fmt.Println(runtime.GOARCH)

        fmt.Println(runtime.GOROOT())
        fmt.Println(runtime.Version())
    }

For my situation, I get:

    $ go run main.go
    gc
    darwin
    amd64
    /Users/jeffreyleeli/src/go-darwin_amd64
    go1.2.2

## Machine related info

In the meantime, we can know info about machine, like:

- CPU Num
- ...

`main.go`

    package main

    import (
        "fmt"
        "runtime"
    )

    func main() {
        fmt.Println(runtime.NumCPU())
    }

On my machine, I get:

    $ go run main.go
    4

## Anything else?

Of course! If you dive deep enough, you can get things about `goroutines`, `callers` etc, as well as `debug` info and other interesting ones.

So **go** for it.
