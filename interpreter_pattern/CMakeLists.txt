cmake_minimum_required(VERSION 3.27)
project("Pattern Interpreter" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
        src/FixBracketsSpace.cpp
        src/RemoveExtraNewLines.cpp
        src/RemoveExtraSpace.cpp
        src/ReplaceHyphenWithDash.cpp
        src/ReplaceQuotes.cpp
        src/TextInterpret.cpp
        src/utils.cpp
        src/main.cpp)

add_executable(PatternInterpreter ${SOURCES})
