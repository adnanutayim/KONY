#ifndef PHASEOBSERVER_H
#define PHASEOBSERVER_H

#include "observer.h"
#include "mainwindow.h"

// This class inherets Observer class
class PhaseObserver : public Observer
{
public:
    PhaseObserver();                    // Default constructro
    PhaseObserver(Ui::MainWindow*&);    // Also constructor - but not default
    void Update();                      // This function updates

private:
    Ui::MainWindow *ui;                 // Reference to UI

};

#endif // PHASEOBSERVER_H
