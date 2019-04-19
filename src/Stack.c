#include "Stack.h"
#include <stdlib.h>
#include <assert.h>

typedef struct StackNode StackNode_t;
typedef struct StackStruct StackStruct_t;

struct StackNode
{
	void *item;
	StackNode_t *below;
};

struct StackStruct
{
	StackNode_t *top;
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
	assert(stack);

	Stack_Clear(stack);

	free(stack);
}

int Stack_Count(Stack_t stack)
{
	assert(stack);

	return stack->count;
}

int Stack_Push(Stack_t stack, void *item)
{
	assert(stack);

	StackNode_t *node = malloc(sizeof(StackNode_t));
	if (node == NULL)
	{
		return -1;
	}

	node->item = item;
	node->below = stack->top;

	stack->top = node;
	stack->count++;

	return 0;
}

void *Stack_Peek(Stack_t stack)
{
	assert(stack);

	if (stack->top == NULL)
	{
		return NULL;
	}

	return stack->top->item;
}

void *Stack_Pop(Stack_t stack)
{
	assert(stack);

	if (stack->top == NULL)
	{
		return NULL;
	}

	StackNode_t *node = stack->top;

	stack->top = node->below;
	stack->count--;

	void *result = node->item;

	free(node);

	return result;
}

void Stack_Clear(Stack_t stack)
{
	assert(stack);

	while(stack->count > 0)
	{
		Stack_Pop(stack);
	}
}

bool Stack_Contains(Stack_t stack, void *item)
{
	assert(stack);
	
	StackNode_t *at = stack->top;

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
