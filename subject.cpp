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
    cout << "Attached" << endl;
    _observers.push_back(o);
    cout << "1: " << _observers.size() << endl;
}

void Subject::Detach(Observer* o){
    cout << "Detached" << endl;
    //_observers->remove(o);
    //_observers.erase()
}

void Subject::Notify(){
    cout << _observers.size() << endl;
//    list<Observer *>::iterator i = _observers->begin();
////    for(; i != _observers->end(); ++i){
//    while(i != _observers->end()){
//        (*i)->Update();
//        i++;
//    }
    for (int i = 0; i < _observers.size(); i++) {
        _observers[i]->Update();
    }
}
