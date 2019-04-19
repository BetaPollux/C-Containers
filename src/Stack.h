#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef struct StackStruct * Stack_t;

/**
 * @brief Create Stack
 * 
 * Create a new empty Stack object.
 * This must be matched with a Destroy() call.
 * 
 * @return Stack_t New Stack object. Returns NULL on failure.
 */
Stack_t Stack_Create(void);

/**
 * @brief Destroy Stack
 * 
 * Deallocates the Stack object.
 * 
 * @param stack     The stack.
 */
void Stack_Destroy(Stack_t stack);

/**
 * @brief Stack Count
 * 
 * Return the item count.
 * 
 * @param stack     The stack.
 * @return int      The number of items in the stack.
 */
int Stack_Count(Stack_t stack);

/**
 * @brief Push Item
 * 
 * Push an item onto the top of the stack.
 * 
 * @param stack     The stack.
 * @param item      The item to add.
 * @return int      Returns 0 on success, -1 on error.
 */
int Stack_Push(Stack_t stack, void *item);

/**
 * @brief Pop Item
 * 
 * Pop the item from the top of the stack.
 * 
 * @param stack     The stack.
 * @return void*    The removed item.
 */
void *Stack_Pop(Stack_t stack);

/**
 * @brief Peek Item
 * 
 * Retrieve the item from the top of the stack without removing it.
 * 
 * @param stack     The stack.
 * @return void*    The item at the top of the stack.
 */
void *Stack_Peek(Stack_t stack);

/**
 * @brief Clear Stack
 * 
 * Clears the stack.
 * 
 * @param stack     The stack.
 */
void Stack_Clear(Stack_t stack);

/**
 * @brief Stack Contains
 * 
 * Check whether an item is already in the stack.
 * 
 * @param stack      The stack.
 * @param item      The item to search for.
 * @return          Returns true if found, false otherwise. 
 */
bool Stack_Contains(Stack_t stack, void *item);

#endif // _STACK_H
