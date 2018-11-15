#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include<vector>
using namespace std;

class Observer;

class Subject
{
public:
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify();
    Subject();
    virtual ~Subject();
private:
    //list<Observer*> *_observers;
    vector<Observer*> _observers;
};

#endif // SUBJECT_H
