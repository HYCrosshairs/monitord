#pragma once

namespace system::service::daemon
{
template<class T>
class IObserver
{
public:
    virtual void update(T data) = 0;
};
    
} // namespace system::service::daemon
