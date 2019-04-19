#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

typedef struct QueueStruct * Queue_t;

/**
 * @brief Create Queue
 * 
 * Create a new empty Queue object.
 * This must be matched with a Destroy() call.
 * 
 * @return Queue_t New Queue object. Returns NULL on failure.
 */
Queue_t Queue_Create(void);

/**
 * @brief Destroy Queue
 * 
 * Deallocates the Queue object.
 * 
 * @param queue     The queue.
 */
void Queue_Destroy(Queue_t queue);

/**
 * @brief Queue Count
 * 
 * Return the item count.
 * 
 * @param queue     The queue.
 * @return int      The number of items in the Queue.
 */
int Queue_Count(Queue_t queue);

/**
 * @brief Enqueue Item
 * 
 * Add an item to the back of the queue.
 * 
 * @param queue     The queue.
 * @param item      The item to add.
 * @return int      Returns 0 on success, -1 on error.
 */
int Queue_Enqueue(Queue_t queue, void *item);

/**
 * @brief Dequeue Item
 * 
 * Remove an item from the front of the queue.
 * 
 * @param queue     The queue.
 * @return void*    The removed item. Returns NULL on failure.
 */
void *Queue_Dequeue(Queue_t queue);

/**
 * @brief Peek Item
 * 
 * Retrieve the item from the front of the queue without removing it.
 * 
 * @param queue     The queue.
 * @return void*    The item at the front of the queue. Returns NULL on failure.
 */
void *Queue_Peek(Queue_t queue);

/**
 * @brief Clear Queue
 * 
 * Clears the queue.
 * 
 * @param queue     The queue.
 */
void Queue_Clear(Queue_t queue);

/**
 * @brief Queue Contains
 * 
 * Check whether an item is already in the queue.
 * 
 * @param queue      The queue.
 * @param item      The item to search for.
 * @return          Returns true if found, false otherwise. 
 */
bool Queue_Contains(Queue_t queue, void *item);

#endif // _QUEUE_H
