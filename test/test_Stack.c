#include "unity.h"
#include "Stack.h"

Stack_t stack;

void setUp(void)
{
	stack = Stack_Create();
}

void tearDown(void)
{
	Stack_Destroy(stack);
}

void test_Stack_Create(void)
{
	TEST_ASSERT_NOT_NULL(stack);
}

void test_Stack_InitialCountIsZero(void)
{
	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Stack_PushItemCountIsOne(void)
{
	int item = 5;

	Stack_Push(stack, &item);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(1, count);
}

void test_Stack_Peek_Ptr(void)
{
	int item = 7;

	Stack_Push(stack, &item);

	int *peeked = (int*)Stack_Peek(stack);

	TEST_ASSERT_EQUAL_PTR(&item, peeked);
}

void test_Stack_Peek(void)
{
	int item = 7;

	Stack_Push(stack, &item);

	int peeked = *(int*)Stack_Peek(stack);

	TEST_ASSERT_EQUAL_INT(item, peeked);
}

void test_Stack_Multiple(void)
{
	int item = 5;

	Stack_t other = Stack_Create();

	Stack_Push(stack, &item);

	int count = Stack_Count(other);

	Stack_Destroy(other);

	TEST_ASSERT_EQUAL(0, count);
}

void test_Stack_PeekNoItems(void)
{
	void *item = Stack_Peek(stack);

	TEST_ASSERT_NULL(item);
}

void test_Stack_PopNoItems(void)
{
	void *item = Stack_Pop(stack);

	TEST_ASSERT_NULL(item);
}

void test_Stack_PopOneItem(void)
{
	int item = 3;

	Stack_Push(stack, &item);

	int *itemPtr = (int*)Stack_Pop(stack);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

void test_Stack_PopTooMany(void)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Pop(stack);
	void *ptr = Stack_Pop(stack);

	TEST_ASSERT_NULL(ptr);
}


void test_Stack_PushPopPushPeek(void)
{
	int item = 3;

	Stack_Push(stack, &item);
	Stack_Pop(stack);
	Stack_Push(stack, &item);
	void *itemPtr = Stack_Peek(stack);
	
	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

void test_Stack_PopReducesCount(void)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Pop(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Stack_PeekDoesNotChangeCount(void)
{
	int item = 3;

	Stack_Push(stack, &item);

	Stack_Peek(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(1, count);
}
void test_Stack_PeekTwice(void)
{
	int item = 3;

	Stack_Push(stack, &item);

	void *first = Stack_Peek(stack);
	void *second = Stack_Peek(stack);

	TEST_ASSERT_EQUAL_PTR(first, second);
}

void test_Stack_CountThreeItems(void)
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

void test_Stack_PopThreeItems(void)
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

void test_Stack_ClearZeroItems(void)
{
	Stack_Clear(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Stack_ClearOneItem(void)
{
	int itemA = 1;

	Stack_Push(stack, &itemA);

	Stack_Pop(stack);

	int count = Stack_Count(stack);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Stack_ClearThreeItems(void)
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

void test_Stack_ContainsFalse()
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Stack_Push(stack, &itemA);
	Stack_Push(stack, &itemC);

	bool contains = Stack_Contains(stack, &itemB);

	TEST_ASSERT_FALSE(contains);
}

void test_Stack_Contains()
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

void test_Stack_ContainsEmpty(void)
{
	int item = 7;

	bool contains =	Stack_Contains(stack, &item);

	TEST_ASSERT_FALSE(contains);
}
