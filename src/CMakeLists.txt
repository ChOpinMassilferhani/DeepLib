add_executable(
    test
    main.c
)

set_target_properties(
    test
    PROPERTIES
    C_STANDARD 99
    C_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(
    test
    PRIVATE
    memory
    mathtools
    network
)
