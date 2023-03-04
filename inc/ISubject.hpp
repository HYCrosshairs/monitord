#pragma once

#include "IObserver.hpp"

namespace sys::service::daemon
{
template <class T>
class ISubject
{
public:
    virtual void attach(IObserver<T>* observer) = 0; // suscribe
    virtual void detach(IObserver<T>* observer) = 0; //  unsucribe
    virtual void notify(T data) = 0;
};    
} // namespace sys::service::daemon
