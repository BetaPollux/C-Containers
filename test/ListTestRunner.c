#include "unity_fixture.h"

TEST_GROUP_RUNNER(List)
{
    RUN_TEST_CASE(List, Create);
    RUN_TEST_CASE(List, CountEmpty);
    RUN_TEST_CASE(List, ItemEmpty);
    RUN_TEST_CASE(List, ContainsEmpty);
    RUN_TEST_CASE(List, Add);
    RUN_TEST_CASE(List, Item);
    RUN_TEST_CASE(List, AddThree);
    RUN_TEST_CASE(List, ItemThree);
    RUN_TEST_CASE(List, ItemOutOfRange);
    RUN_TEST_CASE(List, InsertAt);
    RUN_TEST_CASE(List, InsertAtEmpty);
    RUN_TEST_CASE(List, InsertAtOutOfBounds);
    RUN_TEST_CASE(List, First);
    RUN_TEST_CASE(List, Last);
    RUN_TEST_CASE(List, FirstEmpty);
    RUN_TEST_CASE(List, LastEmpty);
    RUN_TEST_CASE(List, FirstAfterInsertAt);
    RUN_TEST_CASE(List, InsertAtFront);
    RUN_TEST_CASE(List, InsertAtEnd);
    RUN_TEST_CASE(List, FirstLastInsertAtEmpty);
    RUN_TEST_CASE(List, RemoveAtEmpty);
    RUN_TEST_CASE(List, RemoveAtOutOfBounds);
    RUN_TEST_CASE(List, RemoveAt);
    RUN_TEST_CASE(List, RemoveAtFront);
    RUN_TEST_CASE(List, RemoveAtEnd);
    RUN_TEST_CASE(List, RemoveAtAllFromFront);
    RUN_TEST_CASE(List, RemoveAtAllFromEnd);
    RUN_TEST_CASE(List, Clear);
    RUN_TEST_CASE(List, ClearEmpty);
    RUN_TEST_CASE(List, Contains);
    RUN_TEST_CASE(List, ContainsMiddle);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(List);
}

int main (int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
