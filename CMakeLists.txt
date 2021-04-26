cmake_minimum_required(VERSION 3.19)
project(minecraft)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/spdlog)

set(
        SRC

        src/mpch.cc src/mpch.h
        src/main.cc

        src/minecraft/common.h

        src/minecraft/core/application.cc src/minecraft/core/application.h
        src/minecraft/core/window.cc src/minecraft/core/window.h

        src/minecraft/render/buffer.h
        src/minecraft/render/context.cc src/minecraft/render/context.h
)

set(
        WIN32_SRC

        src/minecraft/impl/win32/win32_window.cc src/minecraft/impl/win32/win32_window.h
)

set(
        OPENGL_SRC

        vendor/glad/src/gl.c

        src/minecraft/impl/opengl/opengl_context.cc src/minecraft/impl/opengl/opengl_context.h
)

add_executable(
        minecraft

        ${SRC}

        ${WIN32_SRC}
        ${OPENGL_SRC}
)

target_include_directories(
        minecraft

        PRIVATE
        src

        vendor/glfw/include
        vendor/spdlog
        vendor/glad/include
)

target_link_libraries(
        minecraft
        glfw
        spdlog::spdlog
)

target_precompile_headers(
        minecraft
        PRIVATE
        src/mpch.h
)