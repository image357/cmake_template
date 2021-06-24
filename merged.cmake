add_library(
        merged INTERFACE
)

target_link_libraries(
        merged INTERFACE
        sub1
        sub2
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
        VERSION 0.1
        COMPATIBILITY AnyNewerVersion
)

install(
        TARGETS merged sub1 sub2
        EXPORT mergedTargets
        LIBRARY DESTINATION lib/${CMAKE_PROJECT_NAME} COMPONENT Runtime
        ARCHIVE DESTINATION lib/${CMAKE_PROJECT_NAME} COMPONENT Development
        RUNTIME DESTINATION bin COMPONENT Runtime
        PUBLIC_HEADER DESTINATION include/${CMAKE_PROJECT_NAME} COMPONENT Development
)

configure_package_config_file(
        mergedConfig.cmake.in
        ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION lib/cmake/${CMAKE_PROJECT_NAME}
)

install(EXPORT mergedTargets DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})
install(
        FILES
        ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
        ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
        DESTINATION lib/cmake/${CMAKE_PROJECT_NAME}
)

install(
        DIRECTORY src/
        DESTINATION include/${CMAKE_PROJECT_NAME}
        COMPONENT Development
        FILES_MATCHING PATTERN "*.h"
)
