cmake_minimum_required(VERSION 3.29)
project(pingpong)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
find_package(sdl2_image REQUIRED)


add_executable(pingpong main.cpp
        GameClass.cpp
        GameClass.h
        Ball.cpp
        Ball.h)

target_link_libraries(pingpong PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)
