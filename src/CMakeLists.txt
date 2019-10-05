
set(CONTAINERS_SRC 
    List.c
    Queue.c 
    Stack.c
    Allocator.c
)

set(CONTAINERS_HEADERS
    List.h
    Queue.h
    Stack.h
    Allocator.h
)

add_library(Containers
    STATIC
        ${CONTAINERS_SRC}
        ${CONTAINERS_HEADERS}
)

string(JOIN "\;" PUBLIC_HEADER_TAG ${CONTAINERS_HEADERS})

set_target_properties(Containers
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
    PUBLIC_HEADER
        ${PUBLIC_HEADER_TAG}
)

target_compile_options(Containers
   PRIVATE
        ${WARNINGS}
)

target_include_directories(Containers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS Containers
    ARCHIVE
        DESTINATION ${INSTALL_LIBDIR}
    PUBLIC_HEADER
        DESTINATION ${INSTALL_INCLUDEDIR}
)
