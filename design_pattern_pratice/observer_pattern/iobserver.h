#ifndef IOBSERVER_H
#define IOBSERVER_H

// Interface class
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

#endif // IOBSERVER_H
