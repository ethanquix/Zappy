project(alfred_c)
set(CMAKE_C_STANDARD 11)

include(Header.cmake)
PRINT_HEADER()

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

include_directories(macros)
include_directories(OOP/class/Map)
include_directories(OOP/class/String)
include_directories(OOP/class/Vector)

set(SOURCE_UTILS macros/Alfred.h macros/misc/macros.h macros/error/error.h macros/misc/python.h macros/error/error.c)
set(SOURCE_OOP macros/OOP_macros/OOP_macros.h OOP/class/String/String.c OOP/class/String/String.h OOP/class/String/implem/StringImplem1.c OOP/class/String/implem/StringImplem2.c OOP/class/Vector/Vector.h OOP/class/Vector/Vector.c OOP/class/Vector/implem/VectorImplem1.c OOP/class/Vector/implem/VectorImplem2.c OOP/class/Map/MapCI.h OOP/class/Map/MapCI.c OOP/class/Map/implem/MapCIImplem1.c OOP/class/Map/implem/MapCIImplem2.c macros/struct/Vec2I.h)
add_library(alfred_c SHARED ${SOURCE_UTILS} ${SOURCE_OOP})