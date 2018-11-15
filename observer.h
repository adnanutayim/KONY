#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    virtual void Update() = 0;
    virtual ~Observer();

protected:
    Observer();
};

#endif // OBSERVER_H
