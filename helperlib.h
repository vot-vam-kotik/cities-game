#ifndef HELPERLIB_H
#define HELPERLIB_H

#include <QString>
#include <QVector>

#define MAX_CITY_NAME_LEN 168

class HelperLib
{
public:
    // Содержит ли название города ошибки
    static bool isCityValid(const QString& city);
    // Начинается ли строка с заданного символа
    static bool isStrBeginWith(const QString& str, const QChar& ch);
};

#endif // HELPERLIB_H
