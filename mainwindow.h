#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diceroll.h"
#include "map.h"
#include "qlabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void log(string s);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_rollButton_clicked();

    void on_moveButton_clicked();

private:
    Ui::MainWindow *ui;
    DiceRoll dr;
    Map map;
    int rolls [8];
    void setDiceImage(QLabel *, int);
    void set8DiceEnabled(bool flag);
    void set6DiceEnabled(bool flag);
    void setHeader();
    void lockUnlockUI();
    void fillMoveLocations();

};

#endif // MAINWINDOW_H
