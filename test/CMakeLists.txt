# Unity framework

add_library(Unity
    STATIC
        unity.c
        unity.h
        unity_internals.h
        unity_fixture.c
        unity_fixture.h
        unity_fixture_internals.h
        unity_fixture_malloc_overrides.h
)

set_target_properties(Unity
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

target_compile_options(Unity
   PRIVATE
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

target_include_directories(Unity 
    PUBLIC
        /usr/local/lib/Unity/src
        /usr/local/lib/Unity/extras/fixture/src
)

# Test Runners
add_library(ContainersTestRunners
    STATIC
        test_Queue_fixture.c
        test_Queue_runner.c
)

set_target_properties(ContainersTestRunners
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

target_compile_options(ContainersTestRunners
   PRIVATE
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

# Test Executable
add_executable(ContainerTest
    test_main.c
)

set_target_properties(ContainerTest
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

target_compile_options(ContainerTest
   PRIVATE
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

target_link_libraries(ContainerTest
    Unity
    ContainersTestRunners
)

# Tests
add_test(
    
)
