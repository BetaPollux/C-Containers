#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

/**
 * 
 * @file    Allocator
 * @brief   Linear Memory Allocator Module
 * 
 * The Allocator provides a malloc-like interface to a user-provided storage array.
 * This allows dynamic usage with either a statically or dynamically allocated array.
 * More than one Allocator can be instantiated, allowing the creation of isolated,
 * dynamic memory pools for different code modules.
 * 
 * There is no 'free' mechanism for individual allocations. 
 * Each allocator can only be cleared as a whole.
 * The storage array must be of 'int' type, and all allocations are aligned to sizeof(int).
 * 
 * Static usage example:
 *      #define NUM_WORDS   256
 *      #define CAPACITY    (sizeof(int) * NUM_WORDS)
 *      AllocatorStruct_t allocatorStruct;
 *      int storage[NUM_WORDS];
 *      ...
 * 
 *      Allocator_t allocator = Allocator_Init(&allocatorStruct, storage, NUM_WORDS);
 * 
 *      int count = 64;
 *      float *one = Allocator_Alloc(allocator, count * sizeof(float));
 *      float *two = Allocator_Alloc(allocator, count * sizeof(float));
 * 
 *      Allocator_Clear(allocator);
 * 
 *      int len = 127;
 *      char *pch = Allocator_Alloc(allocator, len * sizeof(char));
 *      strcpy(pch, "Using Static Memory like Dynamic!");
 * 
 * Dynamic usage example:
 *      int numWords = 256;
 *      AllocatorStruct_t *allocatorStructPtr = malloc(sizeof(AllocatorStruct_t));
 *      int *storage = malloc(numWords * sizeof(int));
 *      Allocator_t allocator = Allocator_Init(allocatorStructPtr, storage, numWords);
 * 
 *      int count = 64;
 *      float *one = Allocator_Alloc(allocator, count * sizeof(float));
 *      float *two = Allocator_Alloc(allocator, count * sizeof(float));
 * 
 *      Allocator_Clear(allocator);
 * 
 *      int len = 127;
 *      char *pch = Allocator_Alloc(allocator, len * sizeof(char));
 *      strcpy(pch, "Using a Single Malloc With Multiple Allocations!");
 *      ...
 * 
 *      free(storage);
 *      free(allocatorStructPtr);
 */

/* Allocator_t is used for all interfacing after Init */
typedef struct AllocatorStruct * Allocator_t;

/* Do not access AllocatorStruct members directly */
typedef struct AllocatorStruct
{
    int capacity;
    int used;
    int *address;
    int *nextAddress;
} AllocatorStruct_t;

/**
 * @brief Initialize an Allocator
 * 
 * Initializes the members of an AllocatorStruct_t based on the arguments provided.
 * This function does NOT allocate any memory.
 * The user must provide a valid storage address with the required capacity,
 * and the allocator struct must also be a valid memory location.
 * The return value is a re-cast of allocator into Alloactor_t if the arguments are valid,
 * or returns NULL otherwise.
 * 
 * @param allocator         Valid AllocatorStruct_t memory location.
 * @param storage           Valid memory location (int type) to be used by the allocator.
 * @param numWords          Capacity in words (int type).
 * @return Allocator_t      Allocator pointer for all other use, NULL if error.
 */
Allocator_t Allocator_Init(AllocatorStruct_t *allocator, int *storage, int numWords);

/**
 * @brief Used bytes
 * 
 * Returns the numbers of bytes that are currently being used.
 * This will always be a multiple of sizeof(int).
 * 
 * @param allocator     Allocator object.
 * @return int          Number of bytes used.
 */
int Allocator_Used(Allocator_t allocator);


/**
 * @brief Remaining bytes
 * 
 * Returns the numbers of bytes that are available for allocation.
 * This will always be a multiple of sizeof(int).
 * 
 * @param allocator     Allocator object.
 * @return int          Number of bytes remaining.
 */
int Allocator_Remaining(Allocator_t allocator);

/**
 * @brief Allocate memory
 * 
 * Returns a pointer to the internal storage array with the requested size in bytes.
 * The pointer will always be aligned to sizeof(int).
 * Returns NULL if there is insufficient remaining bytes.
 * 
 * @param allocator     Allocator object.
 * @param size          Requested size in bytes.
 * @return void*        Memory location, NULL if error.
 */
void *Allocator_Alloc(Allocator_t allocator, int size);

/**
 * @brief Clear all memory
 * 
 * Clears all memory allocated by this allocator.
 * This function does NOT free dynamic memory.
 * 
 * @param allocator     Allocator object.
 */
void Allocator_Clear(Allocator_t allocator);

#endif // _ALLOCATOR_H
