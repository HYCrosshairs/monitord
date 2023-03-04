#include "CPUTemperatureMonitor.hpp"
#include "CPUTemperatureObserver.hpp"

#include <iostream>

using namespace sys::service::daemon;

int main(int argc, const char* argv[])
{
    CPUTemperatureMonitor cpuTempMonitor;

    CPUTemperatureObserver cpuTempObserver;
    
    cpuTempMonitor.attach(&cpuTempObserver);

    cpuTempMonitor.setTemperature();

    cpuTempMonitor.detach(&cpuTempObserver);
    
    return 0;
}