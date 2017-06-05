cmake_minimum_required(VERSION 3.8)
project(Zappy)

set(CMAKE_C_STANDARD 11)

include(Header.cmake)

PRINT_HEADER()

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

include_directories(includes)
include_directories(utils)
include_directories(utils/OOP)
include_directories(utils/OOP/class)

set(SOURCE_UTILS utils/Alfred.h utils/macros.h utils/error.c utils/error.h)
set(SOURCE_OOP utils/OO_macros.h utils/OOP/class/String.c utils/OOP/class/String.h utils/OOP/class/implem/StringImplem1.c)

set(SOURCE_FILES_ZAPPY main.c ${SOURCE_UTILS} ${SOURCE_OOP} utils/OOP/class/implem/StringImplem2.c utils/OOP/class/Vector.h utils/OOP/class/Vector.c utils/OOP/class/implem/VectorImplem1.c)
add_executable(Zappy ${SOURCE_FILES_ZAPPY})

# Tests
add_executable(SampleOOP tests/SampleOOP.c utils/Alfred.h utils/macros.h utils/OO_macros.h)