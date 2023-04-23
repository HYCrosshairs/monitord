cmake_minimum_required(VERSION 3.7.2)
project(monitord VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wconversion -pedantic -Wformat-security -Wfatal-errors)

find_package(nlohmann_json REQUIRED)

include_directories(inc)

set(SOURCES
    src/SystemObserver.cpp
    src/SystemMonitor.cpp
    src/WeatherStation.cpp
    src/WeatherObserver.cpp
    main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})