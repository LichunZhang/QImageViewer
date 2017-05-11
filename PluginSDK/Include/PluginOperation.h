// Program: QImageViewer
// FileName:PluginOperation.h
// Author:  Lichun Zhang
// Date:    2017/5/9 下午4:28
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#ifndef QIMAGEVIEWER_PLUGINOPERATION_H
#define QIMAGEVIEWER_PLUGINOPERATION_H


#include <string>
#include <vector>
#include <QIcon>

class PluginOperation {
public:
    typedef enum
    {
        NewAdded,
        Modified,
        Deleted
    } DataEvent;

    PluginOperation(const char *name);
    virtual ~PluginOperation();

    // Menu Position
    virtual const char* GetMenuName() const { return nullptr;}

    virtual const char* GetMenuName2() const { return nullptr;}
    virtual const char* GetDisplayName() const { return _name.c_str();}
    virtual const char* GetTooltip() const { return nullptr;}
    virtual bool AddToToolbar() { return false;}
    virtual const QIcon GetIcon() { return QIcon();}

    // Show/Hide
    virtual void Show()=0;
    virtual void Hide(){}
    virtual bool DefaultShow() { return false;}
    virtual bool IsShown() { return false;}

    // Handle Data Events
    virtual void HandleDataEvent(DataEvent e, const char *info, void *data) {}

    static size_t GetOpCount() { return _list_op.size();}
    static PluginOperation* GetOperation(size_t n) { return _list_op[n];}
    static void BroadCastDataEvent(DataEvent e, const char *info, void *data);

protected:
    static std::vector<PluginOperation*> _list_op;

private:

    static void RegisterOperation(PluginOperation* op);
    std::string _name;
};


#endif //QIMAGEVIEWER_PLUGINOPERATION_H