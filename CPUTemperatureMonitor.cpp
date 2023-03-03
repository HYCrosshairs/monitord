#include "CPUTemperatureMonitor.hpp"

#include <algorithm>
#include <fstream>

using namespace system::service::daemon;

CPUTemperatureMonitor::CPUTemperatureMonitor() : mCPUTemp{0.0f} {}

void CPUTemperatureMonitor::attach(IObserver<float>* observer)
{
    observers.push_back(observer);
}

void CPUTemperatureMonitor::detach(IObserver<float>* observer)
{
    auto iterator = std::find(observers.begin(), observers.end(), observer);
    
    if(iterator not_eq observers.end())
    {
        observers.erase(iterator);
    }
}

void CPUTemperatureMonitor::notify(float data)
{
    for (auto observer : observers)
    {
        observer->update(data);
    }
    
}

void CPUTemperatureMonitor::setTemperature()
{
    mCPUTemp = getTemperature();
    notify(mCPUTemp);

}

float CPUTemperatureMonitor::getTemperature() const
{
    float averageCPUTemp{0.0f};
    FILE* file;

    for (uint8_t idxFile = 0; idxFile < CPU_TEMP_IDX_MAX; idxFile++)
    {
        if(file = fopen(TEMP_FILES[idxFile], "r"))
        {
            // TODO:
        }
    
    return averageCPUTemp;
}
