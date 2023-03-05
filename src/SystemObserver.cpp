#include "SystemObserver.hpp"

#include <iostream>

using namespace service::system::daemon;

void SystemObserver::update(float temperature)
{
    std::cout << "CPU Temp " << temperature << " °C\n";
}
