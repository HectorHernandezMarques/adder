add_simple_library(libadder_lib OBJECT
        Adder.cpp
        )

target_link_libraries(libadder_lib
        PRIVATE
            libadder_include_libadder
        )