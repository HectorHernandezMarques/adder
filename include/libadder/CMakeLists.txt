add_library(libadder_include_libadder INTERFACE)

target_include_directories(libadder_include_libadder
        INTERFACE
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}/${PROJECT_VERSION}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )

install(DIRECTORY .
        DESTINATION include/${PROJECT_NAME}/${PROJECT_VERSION}
        FILES_MATCHING
        PATTERN "*.h"
        )