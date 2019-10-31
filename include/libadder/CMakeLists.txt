add_library(libadder_include_libadder INTERFACE)

target_include_directories(libadder_include_libadder
        INTERFACE
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

install(DIRECTORY .
        DESTINATION include
        FILES_MATCHING
        PATTERN "*.h"
        )