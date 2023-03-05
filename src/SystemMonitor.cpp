#include "SystemMonitor.hpp"
#include "SystemError.hpp"

#include <algorithm>
#include <fstream>
#include <error.h>
#include <chrono>
#include <thread>

using namespace service::system::daemon;

SystemMonitor::SystemMonitor() : mCPUTemp{0.0f} {}

float SystemMonitor::getTemperature() const
{
    float averageCPUTemp{0.0f};
    int cpuTemp{0};
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
                error = -static_cast<int>(sys::SensorError::SENSORS_ERR_IO);
            }
            else if (rc not_eq 1) 
            {
                error = -static_cast<int>(sys::SensorError::SENSORS_ERR_ACCESS_R); 
            }

            error = fclose(file);

            if(error)
            {
                return error;
            } 

            if (rc == EOF) 
            { 
                return errno == EIO ? -static_cast<int>(sys::SensorError::SENSORS_ERR_IO) : -static_cast<int>(sys::SensorError::SENSORS_ERR_ACCESS_R);
            }
        }
        else
        {
            return static_cast<int>(sys::SensorError::SENSORS_ERR_KERNEL);
        }

        averageCPUTemp += cpuTemp;
    }
    
    return static_cast<float>(averageCPUTemp / (CPU_TEMP_IDX_MAX * 1000));
}

void SystemMonitor::fetchCPUTemperature()
{
    for(int i = 0; i < 60; i++)
    {
        mCPUTemp = getTemperature();
        notify(mCPUTemp);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}