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
        )

# Shared library
add_library(libadder SHARED)

target_link_libraries(libadder
        PUBLIC
            libadder_include_libadder
        PRIVATE
            libadder_lib
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
