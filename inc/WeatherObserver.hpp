#pragma once

#include "IObserver.hpp"

namespace service::network::weather
{
class WeatherObserver : public IObserver<float, float, float>
{
public:
    void update(float temperature, float humidity, float pressure) override;
};   
} // namespace service::network::daemon
