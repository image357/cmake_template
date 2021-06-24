project(sub1)

add_library(
        sub1 STATIC
        ClassA.cpp ClassA.h
)

target_include_directories(
        sub1 INTERFACE
        ${CMAKE_SOURCE_DIR}/src
)
