// Program: QImageViewer
// FileName:Splash.cpp
// Author:  Lichun Zhang
// Date:    2017/5/10 上午12:28
// Copyright (c) 2017 Lichun Zhang. All rights reserved.

#include "../Include/Splash.h"

static QSplashScreen *g_splash = nullptr;

void SetSplashScreen(QSplashScreen *splash) {
    g_splash = splash;
}

QSplashScreen *GetSplashScreen() {
    return g_splash;
}
