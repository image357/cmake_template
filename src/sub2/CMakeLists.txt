project(sub2)

FILE(GLOB_RECURSE SOURCES *.cpp)
FILE(GLOB_RECURSE HEADERS *.h)

add_library(
        sub2 STATIC
        ${SOURCES}
        ${HEADERS}
)

target_include_directories(
        sub2 INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)
