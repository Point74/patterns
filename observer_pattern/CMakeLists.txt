cmake_minimum_required(VERSION 3.27)
project("Observer Pattern" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
        src/Deanery.cpp
        src/Teacher.cpp
        src/Department.cpp
        src/utils.cpp
        src/main.cpp)

add_executable(ObserverPattern ${SOURCES})