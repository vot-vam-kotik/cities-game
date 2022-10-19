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
    MainWindow testWindow = MainWindow();

     // Проверка загрузки данных
     bool ok;
     testWindow.loadCitiesData(&ok);
     QVERIFY(ok);
     QVERIFY(testWindow.cities.size() > 1000);

     // Город начинается не на последнюю букву предыдущего
     QString city = "курск";
     QVERIFY(!HelperLib::isStrBeginWith("абакан", city.back()));
     QVERIFY(HelperLib::isStrBeginWith("казань", city.back()));

     // Город не существует
     QVERIFY(!testWindow.cities.contains("пкпва"));
     QVERIFY(testWindow.cities.contains("азов"));

     // Город уже называли
     testWindow.cities["Москва"] = true;
     QVERIFY(testWindow.isCityWasNamed("Москва"));
     QVERIFY(!testWindow.isCityWasNamed("Новосибирск"));

}
