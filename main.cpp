#include "SystemMonitor.hpp"
#include "SystemObserver.hpp"

#include <nlohmann/json.hpp>

#include <iostream>

using namespace service::system::daemon;

int main(int argc, const char* argv[])
{
    SystemMonitor systemMonitor;

    SystemObserver systemObserver;
    
    systemMonitor.subscribe(&systemObserver);

    systemMonitor.fetchCPUTemperature();

    systemMonitor.unsubscribe(&systemObserver);
    
    return 0;
}
