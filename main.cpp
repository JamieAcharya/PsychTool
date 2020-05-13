#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mw;

    mw.show();
    mw.startMainWindow(); //Draw to window after it's visible

    return app.exec();
}
