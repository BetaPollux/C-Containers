#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef struct StackStruct * Stack_t;

Stack_t Stack_Create(void);

void Stack_Destroy(Stack_t stack);

int Stack_Count(Stack_t stack);

int Stack_Push(Stack_t stack, void *item);

void *Stack_Pop(Stack_t stack);

void *Stack_Peek(Stack_t stack);

void Stack_Clear(Stack_t stack);

bool Stack_Contains(Stack_t stack, void *item);

#endif // _STACK_H
