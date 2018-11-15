#include "subject.h"
#include "observer.h"
#include <iostream>

Subject::Subject(){
//_observers = new list<Observer*>;
}

Subject::~Subject(){
    //delete _observers;
}

void Subject::Attach(Observer* o){
    _observers.push_back(o);
    cout << "1: " << _observers.size() << endl;
}

void Subject::Detach(Observer* o){
    //_observers->remove(o);
    //_observers.erase()
}

void Subject::Notify(){
    for (int i = 0; i < _observers.size(); i++) {
        _observers[i]->Update();
    }
}
