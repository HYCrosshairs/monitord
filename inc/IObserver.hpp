#pragma once

namespace service
{
template <typename ...Args>
class IObserver
{
public:
    virtual void update(Args ...args) = 0;
    virtual ~IObserver() = default;
};
} // namespace service
