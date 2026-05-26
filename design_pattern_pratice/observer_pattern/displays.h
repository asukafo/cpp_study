#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <iostream>

#include "iobserver.h"


// Concrete Class
class CurrentConditionDisplay : public IObserver
{
public:
    void update(float temperature, float humidity, float pressure) override
    {
        temperature_ = temperature;
        humidity_    = humidity;
        pressure_    = pressure;
        display();
    }

    void display() const
    {
        std::cout << "Current Condition: "
                  << temperature_ << "C degrees, "
                  << humidity_ << "% humidity, "
                  << pressure_ << "Pa"
                  << std::endl;
    }

private:
    float temperature_ = 0.0f;
    float humidity_    = 0.0f;
    float pressure_    = 0.0f;
};


class StatisticsDisplay : public IObserver
{
public:
    void update(float temperature, float humidity, float pressure) override
    {
        temperature_ = temperature;
        humidity_    = humidity;
        pressure_    = pressure;

        if (0 == count_)
        {
            min_ = max_ = temperature;
        }
        else
        {
            if (temperature < min_) min_ = temperature;
            if (temperature > max_) max_ = temperature;
        }
        sum_ += temperature;
        ++count_;

        display();
    }

    void display() const
    {
        std::cout << "Temperature Statistics: "
                  << "min " << min_ << "C / "
                  << "avg " << (sum_ / count_) << "C / "
                  << "max " << max_ << "C"
                  << std::endl;
    }

private:
    float temperature_ = 0.0f;
    float humidity_    = 0.0f;
    float pressure_    = 0.0f;

    float min_ = 0.0f;
    float max_ = 0.0f;
    float sum_ = 0.0f;
    int count_ = 0;
};


// Concrete Observer
class ForecastDisplay : public IObserver
{
public:
    void update(float temperature, float humidity, float pressure) override
    {
        temperature_ = temperature;
        humidity_    = humidity;
        pressure_    = pressure;

        float last = lastPressure_;
        lastPressure_ = pressure;

        if (pressure > last)
            forecast_ = "Improving weather on the way!";
        else if (pressure == last)
            forecast_ = "More of the same";
        else
            forecast_ = "Watch out for cooler, rainy weather";
        
        display();
    }

    void display() const
    {
        std::cout << "Forecast: " << forecast_ << std::endl;
    }

private:
    float temperature_ = 0.0f;
    float humidity_    = 0.0f;
    float pressure_    = 0.0f;

    float lastPressure_ = 0.0f;
    const char *forecast_ = "No data yet";
};

#endif // DISPLAYS_H