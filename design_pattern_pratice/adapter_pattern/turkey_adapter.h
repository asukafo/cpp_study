#ifndef TURKEY_ADAPTER_H
#define TURKEY_ADAPTER_H

#include "duck.h"
#include "turkey.h"

// Adapter — makes a Turkey look like a Duck via object composition
class TurkeyAdapter : public Duck
{
public:
    explicit TurkeyAdapter(Turkey *turkey) : turkey_(turkey) {}

    void quack() override
    {
        // Turkey doesn't quack, so call gobble instead
        turkey_->gobble();
    }

    void fly() override
    {
        // Turkey flies short distances, so call fly() 5 times to match duck
        for (int i = 0; i < 5; ++i)
            turkey_->fly();
    }

private:
    Turkey *turkey_;
};

#endif // TURKEY_ADAPTER_H
