cmake_minimum_required(VERSION 3.8)
project(Zappy)

set(CMAKE_C_STANDARD 11)

include(Header.cmake)

PRINT_HEADER()

include_directories(includes)
include_directories(utils)

set(SOURCE_FILES_ZAPPY main.c)
add_executable(Zappy ${SOURCE_FILES_ZAPPY})

# Tests
add_executable(SampleOOP tests/SampleOOP.c)