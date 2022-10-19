#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "helperlib.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(1); // Отображаем окно с выбором кол-ва игроков

    bool loadSuccesful = true;
    if (!loadSuccesful)
    {
        // Если не удалось загрузить данные, не даем начать игру
        ui->pb_begin->setEnabled(false);
        ui->sb_playersCount->setEnabled(false);
        return;
    }

    connect(ui->pb_begin, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->pb_submit, &QPushButton::clicked, this, &MainWindow::submitAnswer);
    connect(ui->pb_flee, &QPushButton::clicked, this, &MainWindow::flee);

    emit ui->sb_playersCount->valueChanged(ui->sb_playersCount->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isCityWasNamed(const QString& city)
{
    return cities.value(city);
}

void MainWindow::startGame()
{
    // Добавляем игроков по указанному количеству
    for (int i = 1; i <= ui->sb_playersCount->value(); i++)
    {
        activePlayers.append(i);
    }

    ui->l_round->setText(QString::number(currRound));
    ui->l_player->setText(QString::number(activePlayers[currPlayerId]));
    ui->l_lastCity->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::submitAnswer()
{

}

void MainWindow::transferTurn()
{
    // Назначаем id следующего игрока
    currPlayerId++;
    // Новый раунд наступает, если все активные игроки ответили
    if (currPlayerId > activePlayers.size() - 1)
    {
        currPlayerId = 0;
        currRound++;
        ui->l_round->setText(QString::number(currRound));
    }
    ui->l_player->setText(QString::number(activePlayers[currPlayerId]));
    ui->le_city->setText("");
}

void MainWindow::flee()
{
    ui->statusBar->showMessage(tr("Игрок %1 сдается!").arg(activePlayers[currPlayerId]));
    activePlayers.remove(currPlayerId);
    currPlayerId--; // Сдвигаем id активного игрока назад, т.к. передача хода его увеличивает
    if (activePlayers.size() == 1)
    {
        endGame(); // Завершаем игру, если остался один игррок
    }

    transferTurn();
}

void MainWindow::endGame()
{
    ui->statusBar->showMessage(tr("Игрок %1 победил!").arg(activePlayers[0]));
    // Блокируем дальнейший ввод
    ui->le_city->setEnabled(false);
    ui->pb_flee->setEnabled(false);
    ui->pb_submit->setEnabled(false);
}
