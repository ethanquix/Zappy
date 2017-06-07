project(alfred)
set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

include_directories(macros)
include_directories(OOP/class/Map)
include_directories(OOP/class/String)
include_directories(OOP/class/Vector)

set(SOURCE_UTILS ${CMAKE_CURRENT_SOURCE_DIR}/macros/Alfred.h ${CMAKE_CURRENT_SOURCE_DIR}/macros/misc/macros.h ${CMAKE_CURRENT_SOURCE_DIR}/macros/error/error.h)
set(SOURCE_OOP ${CMAKE_CURRENT_SOURCE_DIR}/macros/OOP_macros/OOP_macros.h ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/String/String.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/String/String.h ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/String/implem/StringImplem1.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/String/implem/StringImplem2.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Vector/Vector.h ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Vector/Vector.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Vector/implem/VectorImplem1.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Vector/implem/VectorImplem2.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Map/MapCI.h ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Map/MapCI.c ${CMAKE_CURRENT_SOURCE_DIR}/OOP/class/Map/implem/MapCIImplem1.c)
add_library(alfred SHARED ${SOURCE_UTILS} ${SOURCE_OOP})