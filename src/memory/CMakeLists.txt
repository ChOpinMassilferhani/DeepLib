add_library(
    memory
    STATIC
    memory.c
)

target_include_directories(
    mathtools
    PUBLIC
    .
    )

target_link_libraries(
    memory
    PRIVATE
    )

set_target_properties(
    memory
    PROPERTIES
    C_STANDARD 99
    C_EXTENSIONS OFF
    )

target_compile_definitions(
    memory
    PUBLIC
    "_GNU_SOURCE"
    )
