---
layout: post
title: "Sheet style dialog with Qt"
description: ""
category: Programs
tags: [qt]
---
{% include JB/setup %}

Sheet style is a nice feature on macOS, to achieve it in Qt, all you need are following two statements.

    QMessageBox *msgBox = new QMessageBox(parent);
    msgBox->setWindowFlags(Qt::Sheet);
    // ...

What does it look like?

![Sheet Style](../../../../image/sheet-style.png)
