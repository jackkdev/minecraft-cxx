cmake_minimum_required(VERSION 3.19)
project(minecraft)

set(CMAKE_CXX_STANDARD 20)

set(
        SRC

        src/main.cc

        src/core/window.h src/core/window.cc

        src/render/buffer.h
)

set(
        WIN32_SRC

        src/impl/win32/win32_window.cc src/impl/win32/win32_window.h
)

add_executable(minecraft ${SRC} ${WIN32_SRC})

target_include_directories(
        minecraft

        PRIVATE
        src
)