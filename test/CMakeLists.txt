# Unity framework

if (NOT UNITY_ROOT)
	set(UNITY_ROOT /usr/local/lib/Unity CACHE PATH "Location of Unity repo")
endif()

set(UNITY_HOME          ${UNITY_ROOT}/src)
set(UNITY_FIXTURE_HOME  /usr/local/lib/Unity/extras/fixture/src)

add_library(Unity
    STATIC
        ${UNITY_HOME}/unity.c
        ${UNITY_HOME}/unity.h
        ${UNITY_HOME}/unity_internals.h
        ${UNITY_FIXTURE_HOME}/unity_fixture.c
        ${UNITY_FIXTURE_HOME}/unity_fixture.h
        ${UNITY_FIXTURE_HOME}/unity_fixture_internals.h
        ${UNITY_FIXTURE_HOME}/unity_fixture_malloc_overrides.h
)

set_target_properties(Unity
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
)

target_include_directories(Unity 
    PUBLIC
        ${UNITY_HOME}
        ${UNITY_FIXTURE_HOME}
)

# Create Unity Test
function(add_unity_test NAME)
    add_executable(Test-${NAME}
        ${NAME}TestFixture.c
        ${NAME}TestRunner.c
    )

    set_target_properties(Test-${NAME}
        PROPERTIES
            C_STANDARD 99
            C_EXTENSTIONS OFF
            C_STANDARD_REQUIRED ON
    )

    target_compile_options(Test-${NAME}
        PRIVATE
            ${WARNINGS}
    )

    target_link_libraries(Test-${NAME}
        PRIVATE
            Unity
            Containers
    )

    add_test(
        NAME Unity-Test-${NAME}
        COMMAND $<TARGET_FILE:Test-${NAME}>
    )
endfunction()

add_unity_test(Queue)
add_unity_test(List)
add_unity_test(Stack)
add_unity_test(Allocator)
