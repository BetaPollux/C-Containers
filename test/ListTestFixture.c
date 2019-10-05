#include "unity_fixture.h"
#include "List.h"


//Contains determines if an element is already contained

List_t list;

TEST_GROUP(List);

TEST_SETUP(List)
{
    list = List_Create();
}

TEST_TEAR_DOWN(List)
{
    List_Destroy(list);
}

TEST(List, Create)
{
    TEST_ASSERT_NOT_NULL(list);
}

TEST(List, CountEmpty)
{
    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(List, ItemEmpty)
{
    void *item = List_Item(list, 0);

    TEST_ASSERT_NULL(item);
}

TEST(List, ContainsEmpty)
{
    int item = 5;

    bool contains = List_Contains(list, &item);

    TEST_ASSERT_FALSE(contains);
}

TEST(List, Add)
{
    int item = 3;

    List_Add(list, &item);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(1, count);
}

TEST(List, Item)
{
    int item = 3;

    List_Add(list, &item);

    int *ptr = List_Item(list, 0);

    TEST_ASSERT_EQUAL_PTR(&item, ptr);
}

TEST(List, AddThree)
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

TEST(List, ItemThree)
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

TEST(List, ItemOutOfRange)
{
    int itemA = 3;

    List_Add(list, &itemA);

    int *ptr = List_Item(list, 1);

    TEST_ASSERT_NULL(ptr);
}

TEST(List, InsertAt)
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

TEST(List, InsertAtEmpty)
{
    int itemA = 3;

    List_InsertAt(list, &itemA, 0);

    int *ptrA = List_Item(list, 0);
    int count = List_Count(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptrA);
    TEST_ASSERT_EQUAL_INT(1, count);
}

TEST(List, InsertAtOutOfBounds)
{
    int itemA = 3;

    int r = List_InsertAt(list, &itemA, 1);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(-1, r);
    TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(List, First)
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

TEST(List, Last)
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

TEST(List, FirstEmpty)
{
    int *ptr = List_First(list);

    TEST_ASSERT_NULL(ptr);
}

TEST(List, LastEmpty)
{
    int *ptr = List_Last(list);

    TEST_ASSERT_NULL(ptr);
}

TEST(List, FirstAfterInsertAt)
{
    int itemA = 7;

    List_InsertAt(list, &itemA, 0);

    int *ptr = List_First(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, ptr);
}

TEST(List, InsertAtFront)
{
    int itemA = 5;
    int itemB = 7;

    List_Add(list, &itemA);
    List_InsertAt(list, &itemB, 0); 

    int *ptr = List_First(list); //B will push A

    TEST_ASSERT_EQUAL_PTR(&itemB, ptr);
}

TEST(List, InsertAtEnd)
{
    int itemA = 5;
    int itemB = 7;

    List_Add(list, &itemA);
    List_InsertAt(list, &itemB, 1);

    int *ptr = List_Last(list); //B is after A

    TEST_ASSERT_EQUAL_PTR(&itemB, ptr);
}

TEST(List, FirstLastInsertAtEmpty)
{
    int itemA = 5;

    List_InsertAt(list, &itemA, 0);

    int *first = List_First(list);
    int *last = List_Last(list);

    TEST_ASSERT_EQUAL_PTR(&itemA, first);
    TEST_ASSERT_EQUAL_PTR(&itemA, last);
}

TEST(List, RemoveAtEmpty)
{
    void *ptr = List_RemoveAt(list, 0);

    TEST_ASSERT_NULL(ptr);
}

TEST(List, RemoveAtOutOfBounds)
{
    int itemA = 7;

    List_Add(list, &itemA);

    void *ptr = List_RemoveAt(list, 1);

    TEST_ASSERT_NULL(ptr);
}

TEST(List, RemoveAt)
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

TEST(List, RemoveAtFront)
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

TEST(List, RemoveAtEnd)
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

TEST(List, RemoveAtAllFromFront)
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

TEST(List, RemoveAtAllFromEnd)
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

TEST(List, Clear)
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

TEST(List, ClearEmpty)
{
    List_Clear(list);

    int count = List_Count(list);

    TEST_ASSERT_EQUAL_INT(0, count);
}

TEST(List, Contains)
{
    int item = 9;

    List_Add(list, &item);

    bool contains = List_Contains(list, &item);

    TEST_ASSERT_TRUE(contains);
}

TEST(List, ContainsMiddle)
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
