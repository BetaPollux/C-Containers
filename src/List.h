#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct ListStruct * List_t;

List_t List_Create(void);

void List_Destroy(List_t list);

int List_Count(List_t list);

void *List_Item(List_t list, int index);

bool List_Contains(List_t list, void *item);

int List_Add(List_t list, void *item);

int List_InsertAt(List_t list, void *item, int index);

void *List_RemoveAt(List_t list, int index);

void List_Clear(List_t list);

void *List_First(List_t list);

void *List_Last(List_t list);

#endif // _LIST_H
