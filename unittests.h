#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <QObject>
#include <QTest>

#include <helperlib.h>
#include <mainwindow.h>

class UnitTests : public QObject
{
    Q_OBJECT

private slots:
    void testCityValidation();
    void testCityNormalInput();
};

#endif // UNITTESTS_H
