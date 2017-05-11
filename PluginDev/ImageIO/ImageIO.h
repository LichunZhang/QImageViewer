// Program: QImageViewer
// FileName:ImageIO.h
// Author:  Lichun Zhang
// Date:    2017/5/9 下午9:01
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#ifndef QIMAGEVIEWER_IMAGE_IO_H
#define QIMAGEVIEWER_IMAGE_IO_H


#include "PluginOperation.h"

class QImage;

class ImageIO : PluginOperation {
public:

    const char *GetMenuName() const override { return "File(&F)"; }

    const char *GetDisplayName() const override { return "Open Image"; }

    const char *GetTooltip() const override { return "Open Image File"; }

    bool AddToToolbar() override { return true; }

    const QIcon GetIcon() override;

    void Show() override;

    static ImageIO *GetOperation() { return &_instance; }

private:
    ImageIO();

    virtual ~ImageIO();

    static ImageIO _instance;

};


#endif //QIMAGEVIEWER_IMAGE_IO_H