cmake_minimum_required(VERSION 3.21)
project(CS112_Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS112_Assignment_3
        invert_image.cpp bmplib.cpp)

add_executable(Rotate rotate_image.cpp bmplib.cpp)


