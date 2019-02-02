#include "unity.h"
#include "List.h"


//Contains determines if an element is already contained

List_t list;

void setUp(void)
{
    list = List_Create();
}

void tearDown(void)
{
    List_Destroy(list);
}

void test_List_Create(void)
{
    TEST_ASSERT_NOT_NULL(list);
}

void test_List_CountEmpty(void)
{
    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(0, count);
}

void test_List_ItemEmpty(void)
{
    void *item = List_Item(list, 0);

    TEST_ASSERT_NULL(item);
}

void test_List_ContainsEmpty(void)
{
    int item = 5;

    bool contains = List_Contains(list, &item);

    TEST_ASSERT_FALSE(contains);
}

void test_List_Add(void)
{
    int item = 3;

    List_Add(list, &item);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(1, count);
}

void test_List_Item(void)
{
    int item = 3;

    List_Add(list, &item);

    int *ptr = List_Item(list, 0);

    TEST_ASSERT_EQUAL_PTR(&item, ptr);
}

void test_List_AddThree(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(3, count);
}

void test_List_ItemThree(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    int *ptrA = List_Item(list, 0);
    int *ptrB = List_Item(list, 1);
    int *ptrC = List_Item(list, 2);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptrA);
    TEST_ASSERT_EQUAL_PTR(&itemB, ptrB);
    TEST_ASSERT_EQUAL_PTR(&itemC, ptrC);
}

void test_List_ItemOutOfRange(void)
{
    int itemA = 3;

    List_Add(list, &itemA);

    int *ptr = List_Item(list, 1);

    TEST_ASSERT_NULL(ptr);
}

void test_List_InsertAt(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);

    List_InsertAt(list, &itemC, 1); //between A and B

    int *ptrA = List_Item(list, 0);
    int *ptrC = List_Item(list, 1); //C is inbetween
    int *ptrB = List_Item(list, 2); //B is pushed 

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptrA);
    TEST_ASSERT_EQUAL_PTR(&itemB, ptrB);
    TEST_ASSERT_EQUAL_PTR(&itemC, ptrC);
    TEST_ASSERT_EQUAL_INT(3, count);
}

void test_List_InsertAtEmpty(void)
{
    int itemA = 3;

    List_InsertAt(list, &itemA, 0);

    int *ptrA = List_Item(list, 0);
    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptrA);
    TEST_ASSERT_EQUAL_INT(1, count);
}

void test_List_InsertAtOutOfBounds(void)
{
    int itemA = 3;

    int r = List_InsertAt(list, &itemA, 1);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(-1, r);
    TEST_ASSERT_EQUAL_INT(0, count);
}

void test_List_First(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    int *ptr = List_First(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptr);
}

void test_List_Last(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    int *ptr = List_Last(list);

    TEST_ASSERT_EQUAL_PTR(&itemC, ptr);
}

void test_List_FirstEmpty(void)
{
    int *ptr = List_First(list);

    TEST_ASSERT_NULL(ptr);
}

void test_List_LastEmpty(void)
{
    int *ptr = List_Last(list);

    TEST_ASSERT_NULL(ptr);
}

void test_List_FirstAfterInsertAt(void)
{
    int itemA = 7;

    List_InsertAt(list, &itemA, 0);

    int *ptr = List_First(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptr);
}

void test_List_InsertAtFront(void)
{
    int itemA = 5;
    int itemB = 7;

    List_Add(list, &itemA);
    List_InsertAt(list, &itemB, 0); 

    int *ptr = List_First(list); //B will push A

    TEST_ASSERT_EQUAL_PTR(&itemB, ptr);
}

void test_List_InsertAtEnd(void)
{
    int itemA = 5;
    int itemB = 7;

    List_Add(list, &itemA);
    List_InsertAt(list, &itemB, 1);

    int *ptr = List_Last(list); //B is after A

    TEST_ASSERT_EQUAL_PTR(&itemB, ptr);
}

void test_List_FirstLastInsertAtEmpty(void)
{
    int itemA = 5;

    List_InsertAt(list, &itemA, 0);

    int *first = List_First(list);
    int *last = List_Last(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, first);
    TEST_ASSERT_EQUAL_PTR(&itemA, last);
}

void test_List_RemoveAtEmpty(void)
{
    void *ptr = List_RemoveAt(list, 0);

    TEST_ASSERT_NULL(ptr);
}

void test_List_RemoveAtOutOfBounds(void)
{
    int itemA = 7;

    List_Add(list, &itemA);

    void *ptr = List_RemoveAt(list, 1);

    TEST_ASSERT_NULL(ptr);
}

void test_List_RemoveAt(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    int *removed = List_RemoveAt(list, 1);

    int *ptr = List_Item(list, 1);  //C will fill the gap

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemB, removed);
    TEST_ASSERT_EQUAL_PTR(&itemC, ptr);
    TEST_ASSERT_EQUAL_INT(2, count);
}

void test_List_RemoveAtFront(void)
{
    int itemA = 7;
    int itemB = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);

    int *removed = List_RemoveAt(list, 0);

    int *first = List_First(list);    //B is pushed to front

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, removed);
    TEST_ASSERT_EQUAL_PTR(&itemB, first);
    TEST_ASSERT_EQUAL_INT(1, count);
}

void test_List_RemoveAtEnd(void)
{
    int itemA = 7;
    int itemB = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);

    int *removed = List_RemoveAt(list, 1);

    int *last = List_Last(list);    //A is now end

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemB, removed);
    TEST_ASSERT_EQUAL_PTR(&itemA, last);
    TEST_ASSERT_EQUAL_INT(1, count);
}

void test_List_RemoveAtAllFromFront(void)
{
    int itemA = 7;
    int itemB = 9;
    int itemC = 11;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    List_RemoveAt(list, 0);
    List_RemoveAt(list, 0);
    List_RemoveAt(list, 0);

    int *first = List_First(list);

    TEST_ASSERT_NULL(first);
}

void test_List_RemoveAtAllFromEnd(void)
{
    int itemA = 7;
    int itemB = 9;
    int itemC = 11;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    List_RemoveAt(list, 2);
    List_RemoveAt(list, 1);
    List_RemoveAt(list, 0);

    int *last = List_Last(list);

    TEST_ASSERT_NULL(last);
}

void test_List_Clear(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    List_Clear(list);

    int count = List_Count(list);
    int *first = List_First(list);
    int *last = List_Last(list);

    TEST_ASSERT_EQUAL_INT(0, count);
    TEST_ASSERT_NULL(first);
    TEST_ASSERT_NULL(last);
}

void test_List_ClearEmpty(void)
{
    List_Clear(list);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(0, count);
}

void test_List_Contains(void)
{
    int item = 9;

    List_Add(list, &item);

    bool contains = List_Contains(list, &item);

    TEST_ASSERT_TRUE(contains);
}

void test_List_ContainsMiddle(void)
{
    int itemA = 3;
    int itemB = 7;
    int itemC = 9;

    List_Add(list, &itemA);
    List_Add(list, &itemB);
    List_Add(list, &itemC);

    bool contains = List_Contains(list, &itemB);

    TEST_ASSERT_TRUE(contains);
}
