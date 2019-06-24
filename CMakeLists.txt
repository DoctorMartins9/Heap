project("HeapLibrary" CXX)                              # Project name
cmake_minimum_required(VERSION 3.5)                     # CMake Version

set(CMAKE_CXX_STANDARD 14)                              # C++ 14
set(CMAKE_CXX_STANDARD_REQUIRED ON)                     # Requested

# COMPILATION FLAGS -----------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        add_compile_options("-ggdb")
    else()
        add_compile_options("-g")
    endif()
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options("-O3")
endif()


# CUSTOM TARGETS --------------------------------------------------------------

add_custom_target(clean-all
                  COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
                  COMMAND rm -rf ${PROJECT_SOURCE_DIR}/doc/*
                  COMMENT "scan-build Static Analysis")

find_program(DOXYGEN_FOUND doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc
                      COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxygen.cfg
                      COMMENT "Code documentation")
endif()

# BUILD TARGETS ---------------------------------------------------------------

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable( my_heap ${SRCS} )

add_library(hp ${SRCS})

add_executable(heap_test EXCLUDE_FROM_ALL
               ${PROJECT_SOURCE_DIR}/tests/test.cpp)
target_link_libraries(heap_test hp)

# TEST DIRECTIVES -------------------------------------------------------------

enable_testing()

add_test(NAME IntHeapMax
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
         COMMAND ./heap_test [IntHeapMax])

add_test(NAME FloatHeapTestMax
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
COMMAND ./heap_test [FloatHeapTestMax])

add_test(NAME DoubleHeapTestMax
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
COMMAND ./heap_test [DoubleHeapTestMax])

add_test(NAME IntHeapTestMin
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
         COMMAND ./heap_test [IntHeapTestMin])
