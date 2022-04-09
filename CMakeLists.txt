cmake_minimum_required(VERSION 3.20)
include(cmake/utils/get_cmake_args.cmake)

# start project
project(cmake_template VERSION 1.2.3)
set(CMAKE_CXX_STANDARD 17)

# find dependencies
include(cmake/utils/add_external_package.cmake)
add_external_package(GTest VERSION 1 CMAKE_ARGS ${CMAKE_ARGS})
add_external_package(spdlog VERSION 1 CMAKE_ARGS ${CMAKE_ARGS})

find_package(GTest 1 REQUIRED)
find_package(spdlog 1 REQUIRED)
find_package(Threads REQUIRED)

# add submodules
add_subdirectory(src/sub1)
add_subdirectory(src/sub2)
add_subdirectory(docs EXCLUDE_FROM_ALL)
add_subdirectory(tests EXCLUDE_FROM_ALL)

include(merged.cmake)

# project targets
add_executable(main main.cpp)

target_link_libraries(
        main
        PRIVATE
        spdlog::spdlog
        Threads::Threads
        merged
)

# install routines
set(INSTALL_TARGETS main merged sub1 sub2)
include(cmake/utils/install_targets.cmake)
