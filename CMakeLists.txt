cmake_minimum_required(VERSION 3.17)
project(Kruh)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -pedantic -Werror)
add_executable(Kruh main.cpp kruh.h)