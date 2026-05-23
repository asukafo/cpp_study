#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "iobserver.h"

// Interface class
class ISubject
{
public:
    virtual ~ISubject() = default;
    virtual void registerObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif // ISUBJECT_H
