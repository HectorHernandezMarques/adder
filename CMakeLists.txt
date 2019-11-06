cmake_minimum_required(VERSION 3.14.7)

project(libadder
        VERSION 1.0.0
        LANGUAGES CXX
        )

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(test)

# Static library
add_library(libadder_static STATIC)

target_link_libraries(libadder_static
        PUBLIC
            libadder_include_libadder
        PRIVATE
            libadder_lib
        )

set_target_properties(libadder_static PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "libadder_static_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libadder"
        )

# Shared library
add_library(libadder SHARED)

target_link_libraries(libadder
        PUBLIC
            libadder_include_libadder
        PRIVATE
            libadder_lib
        )

set_target_properties(libadder PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "libadder_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libadder"
        )

install(TARGETS
            libadder
            libadder_static
            libadder_lib
            libadder_include_libadder
        EXPORT libadder_export
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )

install(EXPORT libadder_export
        FILE
            LibAdderTargets.cmake
        NAMESPACE
            LibAdder::
        DESTINATION
            cmake/LibAdder
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
        )

configure_package_config_file(cmake/LibAdderConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfig.cmake
        INSTALL_DESTINATION cmake/LibAdder
        )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfigVersion.cmake
        DESTINATION cmake/LibAdder
        )

export(EXPORT libadder_export
        FILE ${CMAKE_CURRENT_BINARY_DIR}/LibAdderTargets.cmake
        NAMESPACE LibAdder::)

#Register package in user's package registry
export(PACKAGE LibAdder)