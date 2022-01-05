add_library(
        merged INTERFACE
)

target_link_libraries(
        merged
        INTERFACE
        sub1
        sub2
)
