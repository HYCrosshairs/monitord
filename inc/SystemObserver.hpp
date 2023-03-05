#pragma once

#include "IObserver.hpp"

namespace service::system::daemon
{
class SystemObserver : public IObserver<float>
{
public:
    void update(float temperature) override;
};

} // service::system::daemon
