cmake_minimum_required(VERSION 3.14.7)
set(CMAKE_CXX_STANDARD 17)

project(libadder
        VERSION 2.0.3
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
        PREFIX ""
        OUTPUT_NAME "libadder_static_${PROJECT_VERSION}_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libadder_static_${PROJECT_VERSION}"
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
        PREFIX ""
        OUTPUT_NAME "libadder_${PROJECT_VERSION}_$<CONFIG>"
        OUTPUT_NAME_RELEASE "libadder_${PROJECT_VERSION}"
        )

# Installation
set(LIBADDER_CMAKE_INSTALL_DIR lib/cmake/LibAdder-${PROJECT_VERSION})

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
            ${LIBADDER_CMAKE_INSTALL_DIR}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
        )

configure_package_config_file(cmake/LibAdderConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfig.cmake
        INSTALL_DESTINATION ${LIBADDER_CMAKE_INSTALL_DIR}
        )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibAdderConfigVersion.cmake
        DESTINATION ${LIBADDER_CMAKE_INSTALL_DIR}
        )

# This is useless and doesn't allow multi-config builds.
# If a build tree is desired to integrate a project,
# submodule aproach is the right option.
# Otherwise, if we decide to link with exported targets,
# above install functions will provide that targets,
# allowing multi-config artifact generations.
#
#export(EXPORT libadder_export
#        FILE ${CMAKE_CURRENT_BINARY_DIR}/LibAdderTargets.cmake
#        NAMESPACE LibAdder::
#        )
#
#export(PACKAGE LibAdder)