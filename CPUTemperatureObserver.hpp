#pragma once

#include "IObserver.hpp"

namespace system::sercice::daemon
{
class CPUTemperatureObserber : public IObserver<float>
{
    void update(float temperature) override;
};
    
} // namespace system::sercice::daemon
