#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    // This is a pure function
    virtual void Update() = 0;

    // This is a virtual destructor
    virtual ~Observer();

protected:
    // Default constructor
    Observer();

}; // This is the end of class

#endif // OBSERVER_H
