#pragma once

#include "IObserver.hpp"

namespace sys::service::daemon
{
class CPUTemperatureObserver : public IObserver<float>
{
public:
    void update(float temperature) override;
};

} // namespace sys::service::daemon
