add_library(libadder_lib OBJECT
        Adder.cpp
        )

target_include_directories(libadder_lib
        INTERFACE
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

target_link_libraries(libadder_lib
        PRIVATE
            libadder_include_libadder
        )

if(MSVC)
    target_compile_options(libadder_lib
            PRIVATE
                -W4
                -WX
            )
else()
    target_compile_options(libadder_lib
            PRIVATE
                -Wall
                -Wextra
                -Werror
                -pedantic
            )
endif()