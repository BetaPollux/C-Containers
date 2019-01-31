#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

typedef struct QueueStruct * Queue_t;

Queue_t Queue_Create(void);

void Queue_Destroy(Queue_t queue);

int Queue_Count(Queue_t queue);

int Queue_Enqueue(Queue_t queue, void *item);

void *Queue_Dequeue(Queue_t queue);

void *Queue_Peek(Queue_t queue);

void Queue_Clear(Queue_t queue);

bool Queue_Contains(Queue_t queue, void *item);

#endif // _QUEUE_H
