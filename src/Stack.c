#include "Stack.h"
#include <stdlib.h>

typedef struct StackItem StackItem_t;
typedef struct StackStruct StackStruct_t;

struct StackItem
{
	void *item;
	StackItem_t *below;
};

struct StackStruct
{
	StackItem_t *top;
	int count;
};

Stack_t Stack_Create(void)
{
	Stack_t stack = malloc(sizeof(StackStruct_t));
	
	if (stack == NULL)
	{
		return NULL;
	}

	stack->top = NULL;
	stack->count = 0;

	return stack;
}

void Stack_Destroy(Stack_t stack)
{
	Stack_Clear(stack);

	free(stack);
}

int Stack_Count(Stack_t stack)
{
	return stack->count;
}

int Stack_Push(Stack_t stack, void *item)
{
	StackItem_t *stackItem = malloc(sizeof(StackItem_t));
	if (stackItem == NULL)
	{
		return -1;
	}

	stackItem->item = item;
	stackItem->below = stack->top;

	stack->top = stackItem;
	stack->count++;

	return 0;
}

void *Stack_Peek(Stack_t stack)
{
	if ((stack->top == NULL) || (stack->top == NULL))
	{
		return NULL;
	}

	return stack->top->item;
}

void *Stack_Pop(Stack_t stack)
{
	if (stack->top == NULL)
	{
		return NULL;
	}

	StackItem_t *oldTop = stack->top;

	stack->top = oldTop->below;
	stack->count--;

	void *result = oldTop->item;

	free(oldTop);

	return result;
}

void Stack_Clear(Stack_t stack)
{
	while(stack->count > 0)
	{
		Stack_Pop(stack);
	}
}

bool Stack_Contains(Stack_t stack, void *item)
{
	StackItem_t *at = stack->top;

	while (at != NULL)
	{
		if (at->item == item)
		{
			return true;
		}
		else
		{
			at = at->below;
		}
	}

	return false;
}
