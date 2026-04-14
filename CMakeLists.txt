cmake_minimum_required(VERSION 3.20)

# Project name and language
project(ordenacion VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include folder
include_directories(include)

# List all source files
set(SOURCES
    src/main.cpp
    include/burbuja.hpp
    include/heap_sort.hpp
    include/incremento.hpp
    include/merge_sort.hpp
    include/nif.hpp
    include/seleccion.hpp
    include/sequence.hpp
    include/sort_method.hpp
    include/static_sequence.hpp
)

# Create executable
add_executable(ordenacion ${SOURCES})

# Optional: compiler warnings
target_compile_options(ordenacion PRIVATE -Wall -Wextra -Wpedantic)