add_simple_library(libadder_include_libadder INTERFACE)

install(DIRECTORY .
        DESTINATION include/${PROJECT_NAME}/${PROJECT_VERSION}
        FILES_MATCHING
        PATTERN *.h
        )