cmake_minimum_required(VERSION 3.20)

# initialize Hunter
include(lib/HunterGate/cmake/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.320.tar.gz"
        SHA1 "9b4e732afd22f40482c11ad6342f7d336634226f"
        LOCAL
)

# start project
project(cmake_tutorial VERSION 1.2.3)
set(CMAKE_CXX_STANDARD 17)

# find dependencies
find_package(Threads REQUIRED)

# add submodules
add_subdirectory(src/sub1)
add_subdirectory(src/sub2)
add_subdirectory(tests EXCLUDE_FROM_ALL)

include(merged.cmake)

# project targets
add_executable(main main.cpp)

target_link_libraries(
        main
        PRIVATE
        Threads::Threads
        merged
)

# install routines
set(INSTALL_TARGETS main merged sub1 sub2)
include(cmake/install.cmake)
