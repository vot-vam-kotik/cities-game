#include "mainwindow.h"
#include "unittests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new UnitTests, argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
