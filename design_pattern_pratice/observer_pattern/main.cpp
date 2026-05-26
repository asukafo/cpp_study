#include <iostream>

#include "weather_data.h"
#include "displays.h"

int main()
{
    std::cout << "Observer Pattern: defines a one-to-many dependency between objects\n"
              << "so that when one object changes state, all of its dependents are\n"
              << "notified and updated automatically.\n"
              << std::endl;
    std::cout << "=== Observer Pattern: Weather Station ===" << std::endl;

    WeatherData weatherData;

    CurrentConditionDisplay currentDisplay;
    StatisticsDisplay statisticsDisplay;
    ForecastDisplay forecastDisplay;

    weatherData.registerObserver(&currentDisplay);
    weatherData.registerObserver(&statisticsDisplay);
    weatherData.registerObserver(&forecastDisplay);

    std::cout << "\n--- Measurement 1 ---" << std::endl;
    weatherData.setMeasurements(27.0f, 65.0f, 1013.0f);

    std::cout << "\n--- Measurement 2 ---" << std::endl;
    weatherData.setMeasurements(28.5f, 70.0f, 1010.0f);

    std::cout << "\n--- Remove statistics display, Measurement 3 ---" << std::endl;
    weatherData.removeObserver(&statisticsDisplay);
    weatherData.setMeasurements(26.0f, 90.0f, 1008.0f);

    return 0;
}
