#ifndef DISPLAYS_H
#define DISPLAYS_H

#include "iobserver.h"
#include <iostream>

// Concrete Observer: display current conditions
class CurrentConditionsDisplay final : public IObserver
{
public:
    void update(float temperature, float humidity, float /*pressure*/) override
    {
        temperature_ = temperature;
        humidity_ = humidity;
        display();
    }

    void display() const
    {
        std::cout << "Current conditions: "
                  << temperature_ << "C degrees, "
                  << humidity_ << "% humidity"
                  << std::endl;
    }

private:
    float temperature_ = 0.0f;
    float humidity_ = 0.0f;
};

// Concrete Observer: display statistics (min/max/avg temperature)
class StatisticsDisplay final : public IObserver
{
public:
    void update(float temperature, float /*humidity*/, float /*pressure*/) override
    {
        if (count_ == 0)
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
        std::cout << "Temperature stats: "
                  << "min " << min_ << "C / "
                  << "avg " << (sum_ / count_) << "C / "
                  << "max " << max_ << "C"
                  << std::endl;
    }

private:
    float min_ = 0.0f;
    float max_ = 0.0f;
    float sum_ = 0.0f;
    int count_ = 0;
};

// Concrete Observer: display forecast based on pressure change
class ForecastDisplay final : public IObserver
{
public:
    void update(float /*temperature*/, float /*humidity*/, float pressure) override
    {
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
    float lastPressure_ = 0.0f;
    const char *forecast_ = "No data yet";
};

#endif // DISPLAYS_H
