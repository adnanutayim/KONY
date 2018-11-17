#include "subject.h"
#include "observer.h"
#include <iostream>


Subject::Subject(){                                 // default constructor
//_observers = new list<Observer*>;
}

Subject::~Subject(){                                // destructor
    //delete _observers;
}

void Subject::Attach(Observer* o){                  // Attaches objserver
    _observers.push_back(o);
    cout << "1: " << _observers.size() << endl;
}

void Subject::Detach(Observer* o){                  // Detaches the aforementioned observor
    //_observers->remove(o);
    //_observers.erase()
}

void Subject::Notify(){                             // notifies said observor(s)
    for (int i = 0; i < _observers.size(); i++) {
        _observers[i]->Update();
    }
}
