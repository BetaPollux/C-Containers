#include "List.h"
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode * ListNode_t;
typedef struct ListStruct ListStruct_t;

ListNode_t createNode();
ListNode_t getNodeAtAndRoot(List_t list, int index, ListNode_t *root);

struct ListNode
{
	void *item;
	ListNode_t next;
};

struct ListStruct
{
	ListNode_t start;
	ListNode_t end;
	int count;
};

List_t List_Create(void)
{
    ListStruct_t *list = malloc(sizeof(ListStruct_t));
    
    if (list == NULL)
	{
		return NULL;
	}

    list->start = NULL;
    list->end = NULL;
    list->count = 0;

    return list;
}

void List_Destroy(List_t list)
{
    assert(list);

    List_Clear(list);
    free(list);
}

int List_Count(List_t list)
{
    assert(list);

    return list->count;
}

void *List_Item(List_t list, int index)
{
    assert(list);

    ListNode_t node = getNodeAtAndRoot(list, index, NULL);

    if (node != NULL)
    {
        return node->item;
    }
    else
    {
        return NULL;
    }
}

bool List_Contains(List_t list, void *item)
{
    assert(list);

    ListNode_t node = list->start;

    while (node != NULL)
    {
        if (node->item == item)
        {
            return true;
        }

        node = node->next;
    }

    return false;
}

int List_Add(List_t list, void *item)
{
    assert(list);

    ListNode_t node = createNode(item);
    if (node == NULL)
    {
        return -1;
    }
    
    if (list->start == NULL)
    {
        list->start = node;
        list->end = node;
    }
    else
    {
        list->end->next = node;
        list->end = node;
    }
    
    list->count++;

    return 0;
}

int List_InsertAt(List_t list, void *item, int index)
{
    assert(list);

    if (index > list->count)
    {
        return -1;
    }

    ListNode_t newNode = createNode(item);
    if (newNode == NULL)
    {
        return -1;
    }

    ListNode_t rootNode;
    ListNode_t nodeToPush = getNodeAtAndRoot(list, index, &rootNode);

    newNode->next = nodeToPush;

    if (rootNode != NULL)
    {
        rootNode->next = newNode;
    }
    else
    {
        list->start = newNode;
    }

    //inserted at end
    if (newNode->next == NULL)
    {
        list->end = newNode;
    }

    list->count++;

    return 0;
}

void *List_RemoveAt(List_t list, int index)
{
    assert(list);

    ListNode_t rootNode;
    ListNode_t nodeToRemove = getNodeAtAndRoot(list, index, &rootNode);
    if (nodeToRemove == NULL)
    {
        return NULL;
    }

    void * removedItem = nodeToRemove->item;

    if (rootNode != NULL)
    {
        rootNode->next = nodeToRemove->next;
        if (rootNode->next == NULL) //Removing last node
        {
            list->end = rootNode;
        }
    }
    else    //Removing first node
    {
        list->start = nodeToRemove->next;
        if (list->start == NULL)
        {
            list->end = NULL; //Removed all nodes
        }
    }

    free(nodeToRemove);
    list->count--;

    return removedItem;
}

void List_Clear(List_t list)
{
    assert(list);

    ListNode_t node = list->start;

    while (node != NULL)
    {
        ListNode_t nodeToFree = node;
        node = node->next;
        free(nodeToFree);
    }

    list->count = 0;
    list->start = NULL;
    list->end = NULL;
}

void *List_First(List_t list)
{
    assert(list);

    if (list->start != NULL)
    {
        return list->start->item;
    }

    return NULL;
}

void *List_Last(List_t list)
{
    assert(list);

    if (list->end != NULL)
    {
        return list->end->item;
    }

    return NULL;
}

ListNode_t createNode(void *item)
{
    ListNode_t node = malloc(sizeof(struct ListNode));

    if (node != NULL)
    {
        node->item = item;
        node->next = NULL;
    }

    return node;
}

ListNode_t getNodeAtAndRoot(List_t list, int index, ListNode_t *root)
{
    assert(list);
    
    if (index >= list->count)
    {
        if (root != NULL)
        {
            *root = NULL;
        }

        return NULL;
    }

    ListNode_t rootNode = NULL;
    ListNode_t node = list->start;

    for (int i = 0; i < index; i++)
    {
        rootNode = node;
        node = node->next;
    }

    if (root != NULL)
    {
        *root = rootNode;
    }

    return node;
}