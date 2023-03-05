#pragma once

#include "IObserver.hpp"
#include <vector>
#include <algorithm>

namespace service
{
template <typename ...Args>
class ISubject
{
public:
    void subscribe(IObserver<Args...>* observer)
    {
        observers.push_back(observer);
    }

    void unsubscribe(IObserver<Args...>* observer)
    {
        auto iterator = std::find(observers.begin(), observers.end(), observer);
    
        if(iterator not_eq observers.end())
        {
            observers.erase(iterator);
        }
    }

    void notify(Args... args)
    {
        for (auto observer : observers)
        {
            observer->update(std::forward<Args>(args)...);
        }
    }

private:
    std::vector<IObserver<Args...>*> observers;
};    
} // namespace service
