#include "unity.h"
#include "Allocator.h"
#include <string.h>
#include <stdlib.h>

#define NUM_WORDS   8
#define CAPACITY    (sizeof(int) * NUM_WORDS)

int storage[NUM_WORDS];

AllocatorStruct_t allocatorStruct;
Allocator_t allocator;

void setUp(void)
{
    allocator = Allocator_Init(&allocatorStruct, storage, NUM_WORDS);
}

void tearDown(void)
{
}

void test_Allocator_Init(void)
{
    TEST_ASSERT_NOT_NULL(allocator);
    TEST_ASSERT_EQUAL_INT(0, allocator->used);
    TEST_ASSERT_EQUAL_PTR(storage, allocator->address);
    TEST_ASSERT_EQUAL_PTR(storage, allocator->nextAddress);
    TEST_ASSERT_EQUAL_INT(CAPACITY, allocator->capacity);
}

void test_Allocator_InitNull(void)
{
    Allocator_t badAllocator = Allocator_Init(NULL, storage, CAPACITY);

    TEST_ASSERT_NULL(badAllocator);
}

void test_Allocator_InitNullStorage(void)
{
    Allocator_t badAllocator = Allocator_Init(&allocatorStruct, NULL, CAPACITY);

    TEST_ASSERT_NULL(badAllocator);
}

void test_Allocator_AllocOneByte(void)
{
    int *mem = Allocator_Alloc(allocator, 1);
    int used = Allocator_Used(allocator);

    TEST_ASSERT_EQUAL_PTR(storage, mem);
    TEST_ASSERT_EQUAL_INT(sizeof(int), used);
}

void test_Allocator_AllocOneWord(void)
{
    int *mem = Allocator_Alloc(allocator, sizeof(int));
    int used = Allocator_Used(allocator);

    TEST_ASSERT_EQUAL_PTR(storage, mem);
    TEST_ASSERT_EQUAL_INT(sizeof(int), used);
}

void test_Allocator_AllocOneWordPlusByte(void)
{
    int *mem = Allocator_Alloc(allocator, 1 + sizeof(int));
    int used = Allocator_Used(allocator);

    TEST_ASSERT_EQUAL_PTR(storage, mem);
    TEST_ASSERT_EQUAL_INT(2 * sizeof(int), used);
}

void test_Allocator_AllocOneWordTwice(void)
{
    int *memA = Allocator_Alloc(allocator, sizeof(int));
    int *memB = Allocator_Alloc(allocator, sizeof(int));
    int used = Allocator_Used(allocator);

    TEST_ASSERT_EQUAL_PTR(&storage[0], memA);
    TEST_ASSERT_EQUAL_PTR(&storage[1], memB);
    TEST_ASSERT_EQUAL_INT(2 * sizeof(int), used);
}

void test_Allocator_AllocOneWordPlusByteTwice(void)
{
    int *memA = Allocator_Alloc(allocator, 1 + sizeof(int));
    int *memB = Allocator_Alloc(allocator, 1 + sizeof(int));
    int used = Allocator_Used(allocator);

    TEST_ASSERT_EQUAL_PTR(&storage[0], memA);
    TEST_ASSERT_EQUAL_PTR(&storage[2], memB);
    TEST_ASSERT_EQUAL_INT(4 * sizeof(int), used);
}

void test_Allocator_Remaining(void)
{
    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_INT(CAPACITY, remaining);
}

void test_Allocator_AllocFullCapacityFromEmpty(void)
{
    int *mem = Allocator_Alloc(allocator, CAPACITY);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_PTR(&storage[0], mem);
    TEST_ASSERT_EQUAL_INT(0, remaining);    //fully used
}

void test_Allocator_AllocOverCapacityFromEmpty(void)
{
    int *mem = Allocator_Alloc(allocator, CAPACITY + 1);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_NULL(mem);
    TEST_ASSERT_EQUAL_INT(CAPACITY, remaining);
}

void test_Allocator_AllocOverCapacityFromPartial(void)
{
    int *memA = Allocator_Alloc(allocator, 1);
    int *memB = Allocator_Alloc(allocator, CAPACITY);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_PTR(&storage[0], memA);
    TEST_ASSERT_NULL(memB);
    TEST_ASSERT_EQUAL_INT(CAPACITY - sizeof(int), remaining);
}

void test_Allocator_ClearEmpty(void)
{
    Allocator_Clear(allocator);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_INT(CAPACITY, remaining);
}

void test_Allocator_ClearFilled(void)
{
    Allocator_Alloc(allocator, CAPACITY);
    Allocator_Clear(allocator);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_INT(CAPACITY, remaining);
}

void test_Allocator_ClearPartialThenAlloc(void)
{
    Allocator_Alloc(allocator, 1);
    Allocator_Clear(allocator);
    int *mem = Allocator_Alloc(allocator, CAPACITY);

    int remaining = Allocator_Remaining(allocator);

    TEST_ASSERT_EQUAL_PTR(storage, mem);
    TEST_ASSERT_EQUAL_INT(0, remaining);
}

void test_Allocator_ApplicationFloats(void)
{
    float *a = Allocator_Alloc(allocator, sizeof(float));
    float *b = Allocator_Alloc(allocator, sizeof(float));

    *a = 1.25f;
    *b = 3.75f;

    float sum = *a + *b;

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 5.0f, sum);
}

void test_Allocator_ApplicationStrings(void)
{
    const int len = 7;
    char *one = Allocator_Alloc(allocator, len * sizeof(char));
    char *two = Allocator_Alloc(allocator, len * sizeof(char));
    char *three = Allocator_Alloc(allocator, 2 * len * sizeof(char));

    strcpy(one, "Hello");
    strcpy(two, " World");
    strcpy(three, "");

    strcat(three, one);
    strcat(three, two);

    TEST_ASSERT_EQUAL_STRING("Hello", one);
    TEST_ASSERT_EQUAL_STRING(" World", two);
    TEST_ASSERT_EQUAL_STRING("Hello World", three);
}

void test_Allocator_Dynamic(void)
{
    int numWords = CAPACITY / sizeof(int);
    AllocatorStruct_t *pAllocatorStruct = malloc(sizeof(AllocatorStruct_t));
    int *pStorage = malloc(CAPACITY);
    Allocator_t pAllocator = Allocator_Init(pAllocatorStruct, pStorage, numWords);
    
    int len = 32;
    char *pch = Allocator_Alloc(pAllocator, len * sizeof(char));
    
    strcpy(pch, "Dynamic Memory!");

    TEST_ASSERT_EQUAL_STRING("Dynamic Memory!", pch);

    free(pStorage);
    free(pAllocatorStruct);
}