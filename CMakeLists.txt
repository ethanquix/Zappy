cmake_minimum_required(VERSION 3.8)
project(Zappy)

set(CMAKE_C_STANDARD 11)

include(Header.cmake)
PRINT_HEADER()

add_subdirectory(alfred)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

include_directories(includes)
include_directories(alfred/macros)
include_directories(alfred/OOP/class/Map)
include_directories(alfred/OOP/class/String)
include_directories(alfred/OOP/class/Vector)

include_directories(src/class/MapPlayer)
include_directories(src/class/Player)

set(SOURCE_FILES_ZAPPY main.c src/class/MapPlayer/MapCP.c src/class/MapPlayer/MapCP.h src/class/MapPlayer/implem/MapCPImplem1.c src/class/MapPlayer/implem/MapCPImplem2.c src/class/Player/Player.c src/class/Player/Player.h)

add_executable(Zappy ${SOURCE_FILES_ZAPPY})
target_link_libraries(Zappy alfred)



# Tests
add_executable(SampleOOP tests/SampleOOP.c alfred/macros/Alfred.h alfred/macros/misc/macros.h alfred/macros/OOP_macros/OOP_macros.h)