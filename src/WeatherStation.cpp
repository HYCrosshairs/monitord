#include "WeatherStation.hpp"

using namespace service::network::weather;

WeatherStation::WeatherStation() : temperature{0.0f}, humidity{0.0f}, pressure{0.0f}
{
    
}

float WeatherStation::getTemperature() const
{
    return 0.0;
}

float WeatherStation::getHumidity() const
{
    return 0.0;
}

float WeatherStation::getPressure() const
{
    return 0.0;
}

void WeatherStation::fetchMeasurements()
{
    temperature = getTemperature();
    humidity = getHumidity();
    pressure = getPressure();
    notify(temperature, humidity, pressure);
}