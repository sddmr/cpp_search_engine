cmake_minimum_required(VERSION 3.16)
project(MinimalSearch)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Widgets WebEngineWidgets REQUIRED)

add_executable(MinimalSearch main.cpp)
target_link_libraries(MinimalSearch Qt6::Widgets Qt6::WebEngineWidgets)
