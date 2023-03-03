#pragma once

#include "ISubject.hpp"

#include <vector>
#include <stdint.h>

namespace system::service::daemon
{

constexpr char CPU_TEMP_SENSOR_1[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp1_input";
constexpr char CPU_TEMP_SENSOR_2[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp2_input";
constexpr char CPU_TEMP_SENSOR_3[] = "/sys/class/hwmon/hwmon0/device/hwmon0/temp3_input";

static const char* TEMP_FILES[] = { CPU_TEMP_SENSOR_1, 
                                    CPU_TEMP_SENSOR_2, 
                                    CPU_TEMP_SENSOR_3 };

constexpr uint8_t CPU_TEMP_IDX_MAX = 3;

class CPUTemperatureMonitor : public ISubject<float>
{
public:
    CPUTemperatureMonitor(/* args */);
    ~CPUTemperatureMonitor() = default;

    void attach(IObserver<float>* observer) override;
    void detach(IObserver<float>* observer) override;
    void notify(float data) override;

    void setTemperature();
    
private:
    float getTemperature() const;

    float mCPUTemp;
    std::vector<IObserver<float>*> observers;
};   
} // namespace system::service::daemon
