add_library(Containers
    STATIC
        List.c
        List.h
        Queue.c
        Queue.h
        Stack.c
        Stack.h
        Allocator.c
        Allocator.h
)

set_target_properties(Containers
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
)

target_compile_options(Containers
   PRIVATE
        ${WARNINGS}
)

target_include_directories(Containers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
