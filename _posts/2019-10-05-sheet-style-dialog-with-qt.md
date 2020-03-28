---
layout: post
title: "Sheet style dialog with Qt"
description: ""
category: Programs
tags: [qt]
---
{% include JB/setup %}

Sheet style is a nice feature on macOS, to achieve it in Qt, all you need are following statements.

    QMessageBox *msgBox = new QMessageBox(parent);
    
    msgBox->setWindowFlags(Qt::Sheet);
    msgBox->setText("sheet style");

    msgBox->show();

Note:

- `parent` and `Qt::Sheet` are two mandatory conditions.
- `msgBox-> exec();` also works, with the same effect

What does it look like?

![Sheet Style](../../../../image/sheet-style.png)
