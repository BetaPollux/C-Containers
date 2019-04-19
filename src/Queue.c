#include "Queue.h"
#include <stdlib.h>
#include <assert.h>

typedef struct QueueNode QueueNode_t;
typedef struct QueueStruct QueueStruct_t;

struct QueueNode
{
	void *item;
	QueueNode_t *next;
};

struct QueueStruct
{
	QueueNode_t *front;
	QueueNode_t *back;
	int count;
};

Queue_t Queue_Create(void)
{
	Queue_t queue = malloc(sizeof(QueueStruct_t));
	
	if (queue == NULL)
	{
		return NULL;
	}

	queue->front = NULL;
	queue->back = NULL;
	queue->count = 0;

	return queue;
}

void Queue_Destroy(Queue_t queue)
{
	assert(queue);

    Queue_Clear(queue);

	free(queue);
}

int Queue_Count(Queue_t queue)
{
	assert(queue);

	return queue->count;
}

int Queue_Enqueue(Queue_t queue, void *item)
{
	assert(queue);

	QueueNode_t *node = malloc(sizeof(QueueNode_t));
	if (node == NULL)
	{
		return -1;
	}
	node->item = item;
	node->next = NULL;

	if (queue->front == NULL)
	{
		queue->front = node;	//creating first node
	}
	else
	{
		queue->back->next = node;
	}

	queue->back = node;
	queue->count++;

	return 0;
}

void *Queue_Dequeue(Queue_t queue)
{
	assert(queue);

	if (queue->count == 0)
	{
		return NULL;
	}

	QueueNode_t *node = queue->front;

	void *item = node->item;

	queue->front = node->next;
	queue->count--;

	free(node);

	return item;
}

void *Queue_Peek(Queue_t queue)
{
	assert(queue);

	if (queue->front == NULL)
	{
		return NULL;
	}

	return queue->front->item;
}

void Queue_Clear(Queue_t queue)
{
	assert(queue);

	while(queue->count > 0)
	{
		Queue_Dequeue(queue);
	}
}

bool Queue_Contains(Queue_t queue, void *item)
{
	assert(queue);
	
	QueueNode_t *node = queue->front;

	while(node != NULL)
	{
		if (node->item == item)
		{
			return true;
		}

		node = node->next;
	}

	return false;
}
