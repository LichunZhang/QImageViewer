// Program: QImageViewer
// FileName:ImageIO.cpp
// Author:  Lichun Zhang
// Date:    2017/5/9 下午9:01
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#include <QFileDialog>
#include "ImageIO.h"

ImageIO ImageIO::_instance;

ImageIO::ImageIO() : PluginOperation("ImageIO"){}

ImageIO::~ImageIO() {}

void ImageIO::Show() {
    QString file_name = QFileDialog::getOpenFileName(
            nullptr, "Open Image", "",
            "Image Files (*.png *.jpg *.bmp)");
    if(file_name.isEmpty()) return;
    QImage image(file_name);
    BroadCastDataEvent(NewAdded,file_name.toStdString().c_str(),&image);

}

const QIcon ImageIO::GetIcon() {
    return QIcon(":/images/open.png");
}
