#ifndef PHASEOBSERVER_H
#define PHASEOBSERVER_H

#include "observer.h"
#include "mainwindow.h"


class PhaseObserver : public Observer
{
public:
    PhaseObserver();
    PhaseObserver(Ui::MainWindow*&);
    void Update();

private:
    Ui::MainWindow *ui;

};

#endif // PHASEOBSERVER_H
