#pragma once

#include "ISubject.hpp"

namespace service::network::weather
{
class WeatherStation : public ISubject<float, float, float>
{
public:
    WeatherStation();
    ~WeatherStation() = default;

    void fetchMeasurements();

private:
    float getTemperature() const;
    float getHumidity() const;
    float getPressure() const;

    float temperature;
    float humidity;
    float pressure;
};
} // namespace service::network::weather
