---
layout: post
title: "Sheet style dialog with Qt"
description: ""
category: 
tags: []
---
{% include JB/setup %}

    QDialog *

    Qt::WindowModality

    QMessageBox *msgBox = new QMessageBox(&win);
    msgBox->setWindowFlags(Qt::Sheet);
    msgBox->show();
    msgBox->exec();
