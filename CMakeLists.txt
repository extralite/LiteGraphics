cmake_minimum_required(VERSION 3.10)
project(LiteGraphics)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad/cmake)
glad_add_library(glad EXCLUDE_FROM_ALL STATIC LOADER API gl:core=3.3)

set(LITE_GFX_SOURCES
        src/LiteGraphics.cpp
        )

set(LITE_GFX_LIBRARIES
        glad
        )

if (UNIX AND NOT APPLE)
    target_compile_options(glad PRIVATE "-fPIC")
endif ()

add_library(litegfx SHARED ${LITE_GFX_SOURCES})
set_property(TARGET litegfx PROPERTY C_STANDARD 11)
set_property(TARGET litegfx PROPERTY CXX_STANDARD 11)

target_link_libraries(litegfx ${LITE_GFX_LIBRARIES})

target_include_directories(litegfx PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${GLAD_DIR}/include
        )
