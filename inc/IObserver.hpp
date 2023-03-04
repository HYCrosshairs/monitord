#pragma once

namespace sys::service::daemon
{
template <class Obs>
class IObserver
{
public:
    virtual void update(Obs data) = 0;
};
} // namespace sys::service::daemon
