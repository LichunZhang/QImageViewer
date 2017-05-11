// Program: SRC
// FileName:ImageViewer.h
// Author:  Lichun Zhang
// Date:    2017/5/11 上午10:14
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#ifndef SRC_IMAGEVIEWER_H
#define SRC_IMAGEVIEWER_H


#include <PluginOperation.h>

class ImageViewer : public PluginOperation {
public:

    const char *GetMenuName() const override {return "&Visualization";}
    const char *GetTooltip() const override {return "ImageTabViewer";}
    bool DefaultShow() override {return true;}

    void Show() override;

    void Hide() override;

    bool IsShown() override;

    void HandleDataEvent(DataEvent e, const char *info, void *data) override;

    static ImageViewer *GetOperation() { return &_instance; }

private:

    ImageViewer();
    virtual ~ImageViewer();
    static ImageViewer _instance;
//    ImageTabWidget *_tabWidget;
    bool _shown;

};


#endif //SRC_IMAGEVIEWER_H