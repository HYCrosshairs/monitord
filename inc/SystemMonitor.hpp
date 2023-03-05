#pragma once

//#include "IObserver.hpp"
#include "ISubject.hpp"

#include <vector>
#include <stdint.h>

namespace service::system::daemon
{
constexpr char CPU_TEMP_SENSOR_1[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp1_input";
constexpr char CPU_TEMP_SENSOR_2[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp2_input";
constexpr char CPU_TEMP_SENSOR_3[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp3_input";

static const char* TEMP_FILES[] = { CPU_TEMP_SENSOR_1, 
                                    CPU_TEMP_SENSOR_2, 
                                    CPU_TEMP_SENSOR_3 };

constexpr float CPU_TEMP_IDX_MAX = 3.0f;

class SystemMonitor : public ISubject<float>
{
public:
    SystemMonitor();
    ~SystemMonitor() = default;

    void fetchCPUTemperature();
    
    float getTemperature() const;

private:
    float mCPUTemp;
}; 
} // namespace service::system::daemon
