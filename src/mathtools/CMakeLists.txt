add_library(
    mathtools
    STATIC
    matrix.c
)

target_include_directories(
    mathtools
    PUBLIC
    .
    )

target_link_libraries(
    mathtools
    PRIVATE
    )

set_target_properties(
    mathtools
    PROPERTIES
    C_STANDARD 99
    C_EXTENSIONS OFF
    )

target_compile_definitions(
    mathtools
    PUBLIC
    "_GNU_SOURCE"
    )
