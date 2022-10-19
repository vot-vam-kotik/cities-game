#include "helperlib.h"

#include <QRegularExpression>

bool HelperLib::isCityValid(const QString& city)
{
    // Название города может содержать только пробелы или дефисы
    static QRegularExpression re("^(([а-яА-Я]+|([а-яА-Я]+(-| ))+[а-яА-Я]+))$");
    QRegularExpressionMatch match = re.match(city);
    return match.hasMatch();
}

bool HelperLib::isStrBeginWith(const QString& str, const QChar& ch)
{
    return str.front() == ch;
}
