#include "unity_fixture.h"
#include "Stack.h"

Stack_t stack;

TEST_GROUP(Stack);

TEST_SETUP(Stack)
{
	stack = Stack_Create();
}

TEST_TEAR_DOWN(Stack)
{
	Stack_Destroy(stack);
}

TEST(Stack, Create)
{
	TEST_ASSERT_NOT_NULL(stack);
}

TEST(Stack, InitialCountIsZero)
{
	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Stack, PushItemCountIsOne)
{
	int item = 5;

	Stack_Push(stack, &item);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(1, count);
}

TEST(Stack, Peek_Ptr)
{
	int item = 7;

	Stack_Push(stack, &item);

	int *peeked = (int*)Stack_Peek(stack);

	TEST_ASSERT_EQUAL_PTR(&item, peeked);
}

TEST(Stack, Peek)
{
	int item = 7;

	Stack_Push(stack, &item);

	int peeked = *(int*)Stack_Peek(stack);

	TEST_ASSERT_EQUAL_INT(item, peeked);
}

TEST(Stack, Multiple)
{
	int item = 5;

	Stack_t other = Stack_Create();

	Stack_Push(stack, &item);

	int count = Stack_Count(other);

	Stack_Destroy(other);

	TEST_ASSERT_EQUAL(0, count);
}

TEST(Stack, PeekNoItems)
{
	void *item = Stack_Peek(stack);

	TEST_ASSERT_NULL(item);
}

TEST(Stack, PopNoItems)
{
	void *item = Stack_Pop(stack);

	TEST_ASSERT_NULL(item);
}

TEST(Stack, PopOneItem)
{
	int item = 3;

	Stack_Push(stack, &item);

	int *itemPtr = (int*)Stack_Pop(stack);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

TEST(Stack, PopTooMany)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Pop(stack);
	void *ptr = Stack_Pop(stack);

	TEST_ASSERT_NULL(ptr);
}


TEST(Stack, PushPopPushPeek)
{
	int item = 3;

	Stack_Push(stack, &item);
	Stack_Pop(stack);
	Stack_Push(stack, &item);
	void *itemPtr = Stack_Peek(stack);
	
	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

TEST(Stack, PopReducesCount)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Pop(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Stack, PeekDoesNotChangeCount)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Peek(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(1, count);
}
TEST(Stack, PeekTwice)
{
	int item = 3;

	Stack_Push(stack, &item);

	void *first = Stack_Peek(stack);
	void *second = Stack_Peek(stack);

	TEST_ASSERT_EQUAL_PTR(first, second);
}

TEST(Stack, CountThreeItems)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemB);
	Stack_Push(stack, &itemC);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(3, count);
}

TEST(Stack, PopThreeItems)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemB);
	Stack_Push(stack, &itemC);

	int *popC = (int*)Stack_Pop(stack);
	int *popB = (int*)Stack_Pop(stack);
	int *popA = (int*)Stack_Pop(stack);

	TEST_ASSERT_EQUAL_PTR(&itemA, popA);
	TEST_ASSERT_EQUAL_PTR(&itemB, popB);
	TEST_ASSERT_EQUAL_PTR(&itemC, popC);
}

TEST(Stack, ClearZeroItems)
{
	Stack_Clear(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Stack, ClearOneItem)
{
	int itemA = 1;

	Stack_Push(stack, &itemA);

	Stack_Pop(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Stack, ClearThreeItems)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemB);
	Stack_Push(stack, &itemC);

	Stack_Clear(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Stack, ContainsFalse)
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemC);

	bool contains = Stack_Contains(stack, &itemB);

	TEST_ASSERT_FALSE(contains);
}

TEST(Stack, Contains)
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemB);
	Stack_Push(stack, &itemC);

	bool contains = Stack_Contains(stack, &itemB);

	TEST_ASSERT_TRUE(contains);
}

TEST(Stack, ContainsEmpty)
{
	int item = 7;

	bool contains =	Stack_Contains(stack, &item);

	TEST_ASSERT_FALSE(contains);
}
