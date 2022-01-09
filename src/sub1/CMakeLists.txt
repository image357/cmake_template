project(sub1 VERSION 4.5.6)

set(
        SOURCES
        ClassA.cpp
)

set(
        HEADERS
        ../../include/cmake_tutorial/sub1/ClassA.h
        internal.h
)

add_library(
        sub1 STATIC
        ${SOURCES}
        ${HEADERS}
)


include(GNUInstallDirs)
target_include_directories(
        sub1
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src> # for tests
)
