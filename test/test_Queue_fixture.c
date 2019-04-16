#include "unity_fixture.h"
#include "Queue.h"

TEST_GROUP(Queue)

Queue_t queue;

TEST_SETUP(Queue)
{
    queue = Queue_Create();
}

TEST_TEAR_DOWN(Queue)
{
    Queue_Destroy(queue);
}

TEST(Queue, Create)
{
	TEST_ASSERT_NOT_NULL(queue);
}

TEST(Queue, InitialCountIsZero)
{
	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Queue, EnqueueItemCountIsOne)
{
	int item = 5;

	Queue_Enqueue(queue, &item);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(1, count);
}

TEST(Queue, Peek)
{
	int item = 7;

	Queue_Enqueue(queue, &item);

	int *peeked = (int*)Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(&item, peeked);
}

TEST(Queue, Multiple)
{
	int item = 5;

	Queue_t other = Queue_Create();

	Queue_Enqueue(queue, &item);

	int count = Queue_Count(other);

	Queue_Destroy(other);

	TEST_ASSERT_EQUAL(0, count);
}

TEST(Queue, PeekNoItems)
{
	void *item = Queue_Peek(queue);

	TEST_ASSERT_NULL(item);
}

TEST(Queue, DequeueNoItems)
{
	void *item = Queue_Dequeue(queue);

	TEST_ASSERT_NULL(item);
}

TEST(Queue, DequeueOneItem)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	int *itemPtr = (int*)Queue_Dequeue(queue);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

TEST(Queue, DequeueTooMany)
{
	int item = 3;

	Queue_Enqueue(queue, &item);
	
	Queue_Dequeue(queue);
	void *ptr = Queue_Dequeue(queue);

	TEST_ASSERT_NULL(ptr);
}

TEST(Queue, QueueDequeueQueuePeek)
{
	int item = 3;

	Queue_Enqueue(queue, &item);
	Queue_Dequeue(queue);
	Queue_Enqueue(queue, &item);

	void *itemPtr = Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(&item, itemPtr);
}

TEST(Queue, DequeueReducesCount)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	Queue_Dequeue(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Queue, PeekDoesNotChangeCount)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	Queue_Peek(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(1, count);
}
TEST(Queue, PeekTwice)
{
	int item = 3;

	Queue_Enqueue(queue, &item);

	void *first = Queue_Peek(queue);
	void *second = Queue_Peek(queue);

	TEST_ASSERT_EQUAL_PTR(first, second);
}

TEST(Queue, CountThreeItems)
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

TEST(Queue, DequeueThreeItems)
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

TEST(Queue, ClearZeroItems)
{
	Queue_Clear(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Queue, ClearOneItem)
{
	int itemA = 1;

	Queue_Enqueue(queue, &itemA);

	Queue_Dequeue(queue);

	int count = Queue_Count(queue);

	TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(Queue, ClearThreeItems)
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

TEST(Queue, ContainsFalse)
{
	int itemA = 3;
	int itemB = 5;
	int itemC = 7;

	Queue_Enqueue(queue, &itemA);
	Queue_Enqueue(queue, &itemC);

	bool contains = Queue_Contains(queue, &itemB);

	TEST_ASSERT_FALSE(contains);
}

TEST(Queue, Contains)
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

TEST(Queue, ContainsEmpty)
{
	int item = 7;

	bool contains =	Queue_Contains(queue, &item);

	TEST_ASSERT_FALSE(contains);
}
