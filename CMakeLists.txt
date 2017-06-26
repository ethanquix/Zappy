cmake_minimum_required(VERSION 3.8)
project(Zappy)

set(CMAKE_C_STANDARD 11)

include(Header.cmake)
PRINT_HEADER()

add_subdirectory(alfred)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DRELEASE")
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(src/inc)
include_directories(alfred/macros)
include_directories(alfred/OOP/class/Map)
include_directories(alfred/OOP/class/String)
include_directories(alfred/OOP/class/Vector)

include_directories(src/class/MapPlayer)
include_directories(src/class/Player)
include_directories(src/class/Server)
include_directories(src/class/WorldMap)
include_directories(src/class/Socket)
include_directories(src/)

set(SOURCE_FILES_ZAPPY main.c src/class/MapPlayer/MapCP.c src/class/MapPlayer/MapCP.h src/class/MapPlayer/implem/MapCPImplem1.c src/class/MapPlayer/implem/MapCPImplem2.c src/class/Player/Player.c src/class/Player/Player.h src/inc/inventory.h src/class/WorldMap/WorldMap.h src/class/Server/Server.h src/class/Server/Server.c src/class/WorldMap/WorldMap.c src/class/Server/implem/ServerImplem1.c src/inc/team.h src/client_cmd.c src/class/Socket/Socket.c src/class/Socket/Socket.h src/cmd.h src/class/Server/implem/ServerImplem2.c src/class/Server/implem/ServerImplem3.c src/class/Server/implem/ServerImplem4.c src/arg_parser.c src/inc/arg_parser.h src/select.c src/config.h src/cmd/wrapper_1.c src/cmd/wrapper_2.c src/cmd/wrapper_main.c src/cmd/wrapper_3.c src/gui/gui_cmd.c src/client_cmd.c src/class/Server/implem/ServerImplem5.c src/class/Server/implem/ServerImplem6.c src/inc/inventory.c src/gui/gui_cmd_2.c)

add_executable(zappy ${SOURCE_FILES_ZAPPY})
target_link_libraries(zappy alfred_c m)



# Tests

add_executable(test_MapIP src/class/MapPlayer/MapCP.c src/class/MapPlayer/MapCP.h src/class/MapPlayer/implem/MapCPImplem1.c src/class/MapPlayer/implem/MapCPImplem2.c tests/test_MapIP.c src/class/Player/Player.c src/class/Player/Player.h src/inc/inventory.c)
target_link_libraries(test_MapIP alfred_c)