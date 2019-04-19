# Unity framework

set(UNITY_HOME          /usr/local/lib/Unity/src)
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
        ${UNITY_HOME}
        ${UNITY_FIXTURE_HOME}
)

# Test Runners
add_library(ContainersTestRunners
    STATIC
        QueueTestFixture.c
        QueueTestRunner.c
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

target_link_libraries(ContainersTestRunners
    Unity
    Containers
)

# Test Executable
add_executable(ContainersTest
    TestMain.c
)

set_target_properties(ContainersTest
    PROPERTIES
        C_STANDARD 99
        C_EXTENSTIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
)

target_compile_options(ContainersTest
   PRIVATE
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

target_link_libraries(ContainersTest
    ContainersTestRunners
)

# Test Functions

add_test(
    NAME Unit-Tests
    COMMAND $<TARGET_FILE:ContainersTest>
)
