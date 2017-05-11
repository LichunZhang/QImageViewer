#include <iostream>
#include <QApplication>
#include <QSplashScreen>
#include "Splash.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    QSplashScreen splash;
    SetSplashScreen(&splash);
    splash.show();
    MainWindow window;
    window.show();
    splash.finish(&window);
    return app.exec();
}