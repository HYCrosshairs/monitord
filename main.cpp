#include "CPUTemperatureMonitor.hpp"
#include "CPUTemperatureObserver.hpp"

using namespace system::service::daemon;

int main(int argc, const char* argv[])
{
    CPUTemperatureMonitor cpuTempMonitor;

    CpuTemperatureObserver cpuTempObserver;

    cpuTempMonitor.attach(&cpuTempObserver);
    
    return 0;
}