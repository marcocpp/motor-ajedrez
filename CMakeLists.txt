cmake_minimum_required(VERSION 3.10.0)
project(motor-ajedrez VERSION 0.1.0 LANGUAGES C CXX)

add_executable(motor-ajedrez src/main.cpp)

target_include_directories(motor-ajedrez PUBLIC include)