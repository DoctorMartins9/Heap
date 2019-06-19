# CMAKE HEAP

project(my_heap)                                        # Project name

cmake_minimum_required(VERSION 3.5)                     # CMake Version

set(CMAKE_CXX_STANDARD 14)                              # C++ 14
set(CMAKE_CXX_STANDARD_REQUIRED ON)                     # Requested

include_directories("${PROJECT_SOURCE_DIR}/include")    # Set Library path

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp) # Find cpp files in src

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options("-g")
    add_compile_options("-O1")
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        add_compile_options("-fsanitize=adress")
        add_compile_options("-fno-omit-frame-pointer")
    endif()
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options("-O2")
endif()

add_executable( my_heap src/my_heap.cpp )
