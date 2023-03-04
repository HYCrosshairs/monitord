cmake_minimum_required(VERSION 3.7.2)
project(monitord VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall)# -Wextra -Wconversion -pedantic -Wformat-security -Wfatal-errors)

include_directories(inc)

set(SOURCES
    src/CPUTemperatureMonitor.cpp
    src/CPUTemperatureObserver.cpp
    main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})