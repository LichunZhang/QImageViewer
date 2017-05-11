// Program: QImageViewer
// FileName:PluginOperation.cpp
// Author:  Lichun Zhang
// Date:    2017/5/9 下午4:28
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#include "../Include/PluginOperation.h"

std::vector<PluginOperation*> PluginOperation::_list_op;

PluginOperation::PluginOperation(const char *name)
        :_name(name) {
    RegisterOperation(this);
}

PluginOperation::~PluginOperation() {

}


void PluginOperation::RegisterOperation(PluginOperation *op) {
    _list_op.push_back(op);
}

void PluginOperation::BroadCastDataEvent(DataEvent e, const char *info, void *data) {
    size_t count=_list_op.size();
    for (size_t i=0;i<count;i++)
    {
        PluginOperation* op=GetOperation(i);
        if (op->IsShown()) op->HandleDataEvent(e, info, data);
    }
}

