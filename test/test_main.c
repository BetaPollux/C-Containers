#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Queue);
}

int main (argc, char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
