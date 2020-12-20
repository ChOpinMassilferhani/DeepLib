add_library(
    network
    STATIC
    network.c
)

target_include_directories(
    network
    PUBLIC
    .
    ../mathtools
    )

target_link_libraries(
    network
    PRIVATE
    mathtools
    )

set_target_properties(
    network
    PROPERTIES
    C_STANDARD 99
    C_EXTENSIONS OFF
    )

target_compile_definitions(
    network
    PUBLIC
    "_GNU_SOURCE"
    )
