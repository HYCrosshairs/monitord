#include "CPUTemperatureMonitor.hpp"
#include "SystemError.hpp"

#include <algorithm>
#include <fstream>
#include <error.h>

using namespace sys::service::daemon;

CPUTemperatureMonitor::CPUTemperatureMonitor() : mCPUTemp{0} {}

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
    int cpuTemp{};
    FILE* file;

    for (uint8_t idxFile = 0; idxFile < CPU_TEMP_IDX_MAX; idxFile++)
    {
        if(file = fopen(TEMP_FILES[idxFile], "r"))
        {
            int rc{0};
            int error{0};
            

            errno = 0;

            rc = fscanf(file, "%d", &cpuTemp);

            if (rc == EOF and errno == EIO)
            {
                error = -static_cast<int>(SensorError::SENSORS_ERR_IO);
            }
            else if ( rc not_eq 1) 
            {
                error = -static_cast<int>(SensorError::SENSORS_ERR_ACCESS_R); 
            }

            error = fclose(file);

            if(error)
            {
                return error;
            } 

            if ( rc == EOF) 
            { 
                return errno == EIO ? -static_cast<int>(SensorError::SENSORS_ERR_IO) : -static_cast<int>(SensorError::SENSORS_ERR_ACCESS_R);
            }
        }
        else
        {
            return static_cast<int>(SensorError::SENSORS_ERR_KERNEL);
        }
        averageCPUTemp += cpuTemp;

    }
    
    return static_cast<float>(averageCPUTemp / (CPU_TEMP_IDX_MAX * 1000));
}
