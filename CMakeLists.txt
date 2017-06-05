cmake_minimum_required(VERSION 3.8)
project(Zappy)

set(CMAKE_C_STANDARD 11)

include(Header.cmake)

PRINT_HEADER()

include_directories(includes)
include_directories(utils)

set(SOURCE_UTILS utils/Alfred.h utils/macros.h utils/OO_macros.h)

set(SOURCE_FILES_ZAPPY main.c ${SOURCE_UTILS} utils/OOP/class/String.c utils/OOP/class/String.h utils/error.c utils/error.h)
add_executable(Zappy ${SOURCE_FILES_ZAPPY})

# Tests
add_executable(SampleOOP tests/SampleOOP.c utils/Alfred.h utils/macros.h utils/OO_macros.h)