add_library(Containers
    STATIC
        List.c
        List.h
        Queue.c
        Queue.h
        Stack.c
        Stack.h
)

set_target_properties(Containers
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

target_compile_options(Containers
   PRIVATE
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

target_include_directories(Containers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
