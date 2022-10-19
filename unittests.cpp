#include "unittests.h"

void UnitTests::testCityValidation()
{
    // Пустой ввод
    QVERIFY(!HelperLib::isCityValid(""));
    QVERIFY(!HelperLib::isCityValid(" "));
    QVERIFY(!HelperLib::isCityValid("-"));

    // Слишком длинный ввод (наибольшее кол-во символов в названии города = 168)
    QString city = "";
    city.fill('a', 169);
    QVERIFY(!HelperLib::isCityValid(city));

    // Ввод содержит символы (кроме "-" и " ")
    QVERIFY(!HelperLib::isCityValid("Я1я"));
    QVERIFY(!HelperLib::isCityValid("Я-"));
    QVERIFY(!HelperLib::isCityValid("Яя "));

    QVERIFY(HelperLib::isCityValid("Я-я"));
    QVERIFY(HelperLib::isCityValid("Я я"));

    // Ввод без символов
    QVERIFY(HelperLib::isCityValid("Я")); // Одна буква
    QVERIFY(HelperLib::isCityValid("Абакан")); // Несколько букв

    // Ввод не на русском языке
    QVERIFY(!HelperLib::isCityValid("London"));
}

void UnitTests::testCityNormalInput()
{

}
