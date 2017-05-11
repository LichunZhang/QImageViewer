// Program: SRC
// FileName:ImageTabWidget.cpp
// Author:  Lichun Zhang
// Date:    2017/5/11 上午10:00
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#include <QLabel>
#include <QScrollArea>
#include <QDebug>
#include "ImageTabWidget.h"

ImageTabWidget::ImageTabWidget(QWidget *parent) : QTabWidget(parent) {
    setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(int)),
            SLOT(CloseTab(int)));
}

ImageTabWidget::~ImageTabWidget() {

}

void ImageTabWidget::AddImage(QString label, QImage *img) {
    if (!img) return;
    QScrollArea *scroll = new QScrollArea(this);
    QLabel *view = new QLabel(this);
    view->setPixmap(QPixmap::fromImage(*img));
    scroll->setWidget(view);
    int index = addTab(scroll, label);
    setCurrentIndex(index);

}

void ImageTabWidget::CloseTab(int index) {
    QWidget* widget=currentWidget();
    widget->close();
    widget->deleteLater();
}

