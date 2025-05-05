cmake_minimum_required(VERSION 3.27)
project("Game Project" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
        src/core/Enemy.cpp
        src/core/Field.cpp
        src/core/GameManager.cpp
        src/core/Hero.cpp
        src/enums/TypeEnemy.cpp
        src/factory/EnemyFactory.cpp
        src/observers/GameLogger.cpp
        src/observers/GameStatistics.cpp
        src/observers/Subject.cpp
        src/utils/Random.cpp
        src/main.cpp)

add_executable(GameProject ${SOURCE})

target_include_directories(GameProject PRIVATE ${PROJECT_SOURCE_DIR}/include)