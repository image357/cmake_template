project(tests)

hunter_add_package(googletest_local)
find_package(GTest CONFIG REQUIRED)

add_executable(
        tests
        GlobalTest.cpp GlobalTest.h
)

target_link_libraries(
        tests
        PRIVATE
        GTest::gtest GTest::gmock GTest::gmock_main
        merged
)
