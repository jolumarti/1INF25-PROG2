cmake_minimum_required(VERSION 4.3)
project(Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab main.cpp
        src/common.hpp
        src/Helpers.cpp
        src/Helpers.hpp
        src/model/Streamer.cpp
        src/model/Streamer.hpp
        src/model/GestorStreamers.cpp
        src/model/GestorStreamers.hpp
)
