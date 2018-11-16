#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include "game.h"

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();

private slots:
    void on_stayButton_clicked();

    void on_moveButton_clicked();

private:
    Ui::Popup *ui;
    void fillMoveLocations();
};

#endif // POPUP_H
