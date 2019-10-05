#include "unity_fixture.h"

TEST_GROUP_RUNNER(Allocator)
{
    RUN_TEST_CASE(Allocator, Init);
    RUN_TEST_CASE(Allocator, InitNull);
    RUN_TEST_CASE(Allocator, InitNullStorage);
    RUN_TEST_CASE(Allocator, AllocOneByte);
    RUN_TEST_CASE(Allocator, AllocOneWord);
    RUN_TEST_CASE(Allocator, AllocOneWordPlusByte);
    RUN_TEST_CASE(Allocator, AllocOneWordTwice);
    RUN_TEST_CASE(Allocator, AllocOneWordPlusByteTwice);
    RUN_TEST_CASE(Allocator, Remaining);
    RUN_TEST_CASE(Allocator, AllocFullCapacityFromEmpty);
    RUN_TEST_CASE(Allocator, AllocOverCapacityFromEmpty);
    RUN_TEST_CASE(Allocator, AllocOverCapacityFromPartial);
    RUN_TEST_CASE(Allocator, ClearEmpty);
    RUN_TEST_CASE(Allocator, ClearFilled);
    RUN_TEST_CASE(Allocator, ClearPartialThenAlloc);
    RUN_TEST_CASE(Allocator, ApplicationFloats);
    RUN_TEST_CASE(Allocator, ApplicationStrings);
    RUN_TEST_CASE(Allocator, Dynamic);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Allocator);
}

int main (int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
