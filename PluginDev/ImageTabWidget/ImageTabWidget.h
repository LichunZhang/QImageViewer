// Program: SRC
// FileName:ImageTabWidget.h
// Author:  Lichun Zhang
// Date:    2017/5/11 上午10:00
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#ifndef SRC_IMAGETABWIDGET_H
#define SRC_IMAGETABWIDGET_H


#include <QTabWidget>

class ImageTabWidget : public QTabWidget {
Q_OBJECT
public:
    ImageTabWidget(QWidget *parent);

    virtual ~ImageTabWidget();

    void AddImage(QString label, QImage *img);


protected slots:

    void CloseTab(int index);
};


#endif //SRC_IMAGETABWIDGET_H