#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTest>

#define MAX_CITIES_FILE_SIZE 167772160
#define STATUS_BAR_MSG_TIMEOUT 2000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class UnitTests;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Номера невыбывших игроков
    QVector<int> activePlayers;
    // Номер текущего раунда
    int currRound = 1;
    // Id текущего игрока
    int currPlayerId = 0;
    // Хэш-таблица с названиями городов (ключ). Значение - был ли назван город
    QHash<QString, bool> cities;
    // Буква, на которую должен начинаться следующий город
    QChar lastCh;

    // Загружает список городов из файла
    void loadCitiesData(bool* isSuccesful);
    // Возвращает true, если город уже называли
    bool isCityWasNamed(const QString& city);
    // Передает ход следующему игроку
    void transferTurn();
    // Завершает игру
    void endGame();

private slots:
    // Начинает игру
    void startGame();
    // Подтверждение ввода ответа
    void submitAnswer();
    // Игрок сдается
    void flee();
};
#endif // MAINWINDOW_H
