#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include "isubject.h"
#include <vector>
#include <algorithm>

// Concrete Subject
class WeatherData : public ISubject
{
public:
    void registerObserver(IObserver *observer) override
    {
        observers_.push_back(observer);
    }

    void removeObserver(IObserver *observer) override
    {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end())
        {
            observers_.erase(it);
        }
    }

    void notifyObservers() override
    {
        for (auto *observer : observers_)
        {
            observer->update(temperature_, humidity_, pressure_);
        }
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        temperature_ = temperature;
        humidity_ = humidity;
        pressure_ = pressure;
        notifyObservers();
    }

private:
    float temperature_ = 0.0f;
    float humidity_ = 0.0f;
    float pressure_ = 0.0f;
    std::vector<IObserver *> observers_;
};

#endif // WEATHER_DATA_H
