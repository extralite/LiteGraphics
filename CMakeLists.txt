cmake_minimum_required(VERSION 3.10)
project(LiteGraphics)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad/cmake)
glad_add_library(glad EXCLUDE_FROM_ALL STATIC LOADER API gl:core=3.3)

file(GLOB_RECURSE LITE_GFX_SOURCES
        src/LiteGraphics.cpp
        src/ogl/BufferObject.cpp
        src/ogl/ElementBufferObject.cpp
        src/ogl/FragmentShader.cpp
        src/ogl/Shader.cpp
        src/ogl/ShaderProgram.cpp
        src/ogl/VertexBufferObject.cpp
        src/ogl/VertexShader.cpp
        )

if (UNIX AND NOT APPLE)
    target_compile_options(glad PRIVATE "-fPIC")
endif ()

set(LITEGFX_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        CACHE PATH "LiteGraphics include directory" FORCE)

add_library(litegfx SHARED ${LITE_GFX_SOURCES})
set_property(TARGET litegfx PROPERTY C_STANDARD 11)
set_property(TARGET litegfx PROPERTY CXX_STANDARD 11)

target_link_libraries(litegfx PRIVATE glad)

target_include_directories(litegfx PUBLIC ${LITEGFX_INCLUDE_DIRS})
target_include_directories(litegfx PRIVATE ${GLAD_DIR}/include)
