#include "unity_fixture.h"

TEST_GROUP_RUNNER(Stack)
{
    RUN_TEST_CASE(Stack, Create);
    RUN_TEST_CASE(Stack, InitialCountIsZero);
    RUN_TEST_CASE(Stack, PushItemCountIsOne);
    RUN_TEST_CASE(Stack, Peek_Ptr);
    RUN_TEST_CASE(Stack, Peek);
    RUN_TEST_CASE(Stack, Multiple);
    RUN_TEST_CASE(Stack, PeekNoItems);
    RUN_TEST_CASE(Stack, PopNoItems);
    RUN_TEST_CASE(Stack, PopOneItem);
    RUN_TEST_CASE(Stack, PopTooMany);
    RUN_TEST_CASE(Stack, PushPopPushPeek);
    RUN_TEST_CASE(Stack, PopReducesCount);
    RUN_TEST_CASE(Stack, PeekDoesNotChangeCount);
    RUN_TEST_CASE(Stack, PeekTwice);
    RUN_TEST_CASE(Stack, CountThreeItems);
    RUN_TEST_CASE(Stack, PopThreeItems);
    RUN_TEST_CASE(Stack, ClearZeroItems);
    RUN_TEST_CASE(Stack, ClearOneItem);
    RUN_TEST_CASE(Stack, ClearThreeItems);
    RUN_TEST_CASE(Stack, ContainsFalse);
    RUN_TEST_CASE(Stack, Contains);
    RUN_TEST_CASE(Stack, ContainsEmpty);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Stack);
}

int main (int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
