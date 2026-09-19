cmake_minimum_required(VERSION 3.20)

project(Rasterium
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 REQUIRED)

add_executable(rasterium
    src/main.cpp
    src/Application.cpp
)

target_link_libraries(rasterium PRIVATE SDL3::SDL3)