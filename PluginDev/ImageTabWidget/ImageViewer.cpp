// Program: SRC
// FileName:ImageViewer.cpp
// Author:  Lichun Zhang
// Date:    2017/5/11 上午10:14
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#include <ImageTabWidget.h>
#include "ImageViewer.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include "PlatformResources.h"

ImageViewer ImageViewer::_instance;



//#define MDIAREA = PlatformResources::g_workspace;

ImageViewer::ImageViewer() : PluginOperation("ImageViewer"),
                             _shown(false) {
}

ImageViewer::~ImageViewer() {
    if (_shown) Hide();
}

void ImageViewer::Show() {
    if (_shown) return;
    _shown = true;
}

void ImageViewer::Hide() {
    if (!_shown) return;
    _shown = false;
}

bool ImageViewer::IsShown() {
    return _shown;
}

void ImageViewer::HandleDataEvent(DataEvent e, const char *info, void *data) {
    if (!_shown) return;
    QMdiArea *workspace = PlatformResources::g_workspace;
    if (e == PluginOperation::NewAdded) {
        if (QImage *img_data = static_cast<QImage *>(data)) {
            ImageTabWidget *tabWidget =
                    new ImageTabWidget(workspace);
            QString str_info = QString::fromLocal8Bit(info);
            tabWidget->AddImage("Original Image", img_data);
            QMdiSubWindow *subWindow = workspace->addSubWindow(tabWidget);
            subWindow->setWindowTitle(str_info);
            subWindow->show();
        }
    }
}



