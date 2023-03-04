#include "CPUTemperatureObserver.hpp"

#include <iostream>

using namespace sys::service::daemon;

void CPUTemperatureObserver::update(float temperature)
{
    std::cout << "CPU Temp " << temperature << " °C\n";
}