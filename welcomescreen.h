#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QWidget>
#include <string>
#include <iostream>
#include "mainwindow.h"
using namespace std;

namespace Ui {
class welcomeScreen;
}

class welcomeScreen : public QWidget
{
    Q_OBJECT

public:
    explicit welcomeScreen(QWidget *parent = nullptr);
    ~welcomeScreen();

private slots:
    void on_loadButton_clicked();

    void on_createButton_clicked();

    void on_pushButton_clicked();

    void on_playerCharacterEdit_currentTextChanged(const QString &arg1);

    void on_launchGame_clicked();

private:
    MainWindow *mw;
    Ui::welcomeScreen *ui;
    void log(string str);
    int playerCounter;
    void updateImage(string s);

};

#endif // WELCOMESCREEN_H
