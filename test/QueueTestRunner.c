#include "unity_fixture.h"

TEST_GROUP_RUNNER(Queue)
{
    RUN_TEST_CASE(Queue, Create);
    RUN_TEST_CASE(Queue, InitialCountIsZero);
    RUN_TEST_CASE(Queue, EnqueueItemCountIsOne);
    RUN_TEST_CASE(Queue, Peek);
    RUN_TEST_CASE(Queue, Multiple);
    RUN_TEST_CASE(Queue, PeekNoItems);
    RUN_TEST_CASE(Queue, DequeueNoItems);
    RUN_TEST_CASE(Queue, DequeueOneItem);
    RUN_TEST_CASE(Queue, DequeueTooMany);
    RUN_TEST_CASE(Queue, QueueDequeueQueuePeek);
    RUN_TEST_CASE(Queue, DequeueReducesCount);
    RUN_TEST_CASE(Queue, PeekDoesNotChangeCount);
    RUN_TEST_CASE(Queue, PeekTwice);
    RUN_TEST_CASE(Queue, CountThreeItems);
    RUN_TEST_CASE(Queue, DequeueThreeItems);
    RUN_TEST_CASE(Queue, ClearZeroItems);
    RUN_TEST_CASE(Queue, ClearOneItem);
    RUN_TEST_CASE(Queue, ClearThreeItems);
    RUN_TEST_CASE(Queue, ContainsFalse);
    RUN_TEST_CASE(Queue, Contains);
    RUN_TEST_CASE(Queue, ContainsEmpty);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Queue);
}

int main (int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
