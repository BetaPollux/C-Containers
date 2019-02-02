#include "Allocator.h"
#include <stdlib.h>

Allocator_t Allocator_Init(AllocatorStruct_t *allocator, int *storage, int numWords)
{
    if (storage == NULL)
    {
        return NULL;
    }

    if (allocator != NULL)
    {
        allocator->used = 0;
        allocator->address = storage;
        allocator->nextAddress = storage;
        allocator->capacity = numWords * sizeof(int); 
    }

    return allocator;
}

int Allocator_Used(Allocator_t allocator)
{
    return allocator->used;
}

int Allocator_Remaining(Allocator_t allocator)
{
    return (allocator->capacity - allocator->used);
}

void *Allocator_Alloc(Allocator_t allocator, int size)
{
    if (Allocator_Remaining(allocator) < size)
    {
        return NULL;
    }

    int words = size / sizeof(int);   //word usage

    int bytes = words * sizeof(int);  //byte usage

    if (size > bytes)    //size is not a multiple of word size
    {
        words ++;
        bytes = words * sizeof(int);
    }

    int *result = allocator->nextAddress;

    allocator->used += bytes;
    allocator->nextAddress += words;

    return result;
}

void Allocator_Clear(Allocator_t allocator)
{
    allocator->used = 0;
    allocator->nextAddress = allocator->address;
}