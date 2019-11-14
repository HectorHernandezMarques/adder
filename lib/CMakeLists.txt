add_library(libadder_lib OBJECT
        Adder.cpp
        )

target_include_directories(libadder_lib
        INTERFACE
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}_${PROJECT_VERSION}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

target_link_libraries(libadder_lib
        PRIVATE
            libadder_include_libadder
        )

set_target_properties(libadder_lib PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        )

if (MSVC)
    target_compile_options(libadder_lib
            PRIVATE
                -W4
                -WX
            )
else ()
    target_compile_options(libadder_lib
            PRIVATE
                -Wall
                -Wextra
                -Werror
                -pedantic
            )
endif ()