cmake_minimum_required(VERSION 3.19)
project(cmake_tutorial)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/sub1)

add_executable(main main.cpp)

target_link_libraries(
        main
        sub1
)
