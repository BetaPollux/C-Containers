#include "unity.h"
#include "Queue.h"

Queue_t queue;

void setUp(void)
{
    queue = Queue_Create();
}

void tearDown(void)
{
    Queue_Destroy(queue);
}

void test_Queue_Create(void)
{
	TEST_ASSERT_NOT_NULL(queue);
}

void test_Queue_InitialCountIsZero(void)
{
	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Queue_EnqueueItemCountIsOne(void)
{
	int item = 5;

	Queue_Enqueue(queue, &item);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(1, count);
}

void test_Queue_Peek(void)
{
	int item = 7;

	Queue_Enqueue(queue, &item);

	int *peeked = (int*)Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(&item, peeked);
}

void test_Queue_Multiple(void)
{
	int item = 5;

	Queue_t other = Queue_Create();

	Queue_Enqueue(queue, &item);

	int count = Queue_Count(other);

	Queue_Destroy(other);

	TEST_ASSERT_EQUAL(0, count);
}

void test_Queue_PeekNoItems(void)
{
	void *item = Queue_Peek(queue);

	TEST_ASSERT_NULL(item);
}

void test_Queue_DequeueNoItems(void)
{
	void *item = Queue_Dequeue(queue);

	TEST_ASSERT_NULL(item);
}

void test_Queue_DequeueOneItem(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	int *itemPtr = (int*)Queue_Dequeue(queue);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

void test_Queue_DequeueTooMany(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);
	
	Queue_Dequeue(queue);
	void *ptr = Queue_Dequeue(queue);

	TEST_ASSERT_NULL(ptr);
}

void test_Queue_QueueDequeueQueuePeek(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);
	Queue_Dequeue(queue);
	Queue_Enqueue(queue, &item);

	void *itemPtr = Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

void test_Queue_DequeueReducesCount(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	Queue_Dequeue(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Queue_PeekDoesNotChangeCount(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	Queue_Peek(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(1, count);
}
void test_Queue_PeekTwice(void)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	void *first = Queue_Peek(queue);
	void *second = Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(first, second);
}

void test_Queue_CountThreeItems(void)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemB);
	Queue_Enqueue(queue, &itemC);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(3, count);
}

void test_Queue_DequeueThreeItems(void)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemB);
	Queue_Enqueue(queue, &itemC);

	int *deqA = (int*)Queue_Dequeue(queue);
	int *deqB = (int*)Queue_Dequeue(queue);
	int *deqC = (int*)Queue_Dequeue(queue);

	TEST_ASSERT_EQUAL_PTR(&itemA, deqA);
	TEST_ASSERT_EQUAL_PTR(&itemB, deqB);
	TEST_ASSERT_EQUAL_PTR(&itemC, deqC);
}

void test_Queue_ClearZeroItems(void)
{
	Queue_Clear(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Queue_ClearOneItem(void)
{
	int itemA = 1;

	Queue_Enqueue(queue, &itemA);

	int *popA = (int*)Queue_Dequeue(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Queue_ClearThreeItems(void)
{
	int itemA = 1;
	int itemB = 2;
	int itemC = 3;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemB);
	Queue_Enqueue(queue, &itemC);

	Queue_Clear(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_Queue_ContainsFalse()
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemC);

	bool contains = Queue_Contains(queue, &itemB);

	TEST_ASSERT_FALSE(contains);
}

void test_Queue_Contains()
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemB);
	Queue_Enqueue(queue, &itemC);

	bool contains = Queue_Contains(queue, &itemB);

	TEST_ASSERT_TRUE(contains);
}

void test_Queue_ContainsEmpty(void)
{
	int item = 7;

	bool contains =	Queue_Contains(queue, &item);

	TEST_ASSERT_FALSE(contains);
}
