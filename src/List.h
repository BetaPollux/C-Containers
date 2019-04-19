#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct ListStruct * List_t;

/**
 * @brief Create List
 * 
 * Create a new empty List object.
 * This must be matched with a Destroy() call.
 * 
 * @return List_t New List object. Returns NULL on failure.
 */
List_t List_Create(void);

/**
 * @brief Destroy List
 * 
 * Deallocates the List object.
 * 
 * @param list      The list.
 */
void List_Destroy(List_t list);

/**
 * @brief List Count
 * 
 * Return the item count.
 * 
 * @param list      The List.
 * @return int      The number of items in the List.
 */
int List_Count(List_t list);

/**
 * @brief List Item
 * 
 * Retrieve an Item from the List based on its index.
 * 
 * @param list      The list.
 * @param index     The index to retrieve.
 * @return void*    The item from the list. Returns NULL for invalid index.
 */
void *List_Item(List_t list, int index);

/**
 * @brief List Contains
 * 
 * Check whether an item is already in the list.
 * 
 * @param list      The list.
 * @param item      The item to search for.
 * @return          Returns true if found, false otherwise. 
 */
bool List_Contains(List_t list, void *item);

/**
 * @brief Add to List
 * 
 * Add an item to the end of the list.
 * 
 * @param list      The list.
 * @param item      The item to add.
 * @return int      Returns 0 on success, -1 on error.
 */
int List_Add(List_t list, void *item);

/**
 * @brief Insert into List
 * 
 * Add an item at the specified index of the list.
 * 
 * @param list      The list.
 * @param item      The item to add.
 * @param index     The index where to add the item.
 * @return int      Returns 0 on success, -1 on error.
 */
int List_InsertAt(List_t list, void *item, int index);

/**
 * @brief Remove from List
 * 
 * Remove an item from the list at the specified index.
 * The removed item is returned by the function.
 * 
 * @param list      The list.
 * @param index     The index to remove.
 * @return void*    The item which was removed.
 */
void *List_RemoveAt(List_t list, int index);

/**
 * @brief Clear List
 * 
 * Clears the list.
 * 
 * @param list      The list.
 */
void List_Clear(List_t list);

/**
 * @brief First Item from List
 * 
 * Return the first item from the list without removing it.
 * 
 * @param list      The list.
 * @return void*    The first item in the list.
 */
void *List_First(List_t list);

/**
 * @brief   Last Item from List
 * 
 * Return the last item from the list without removing it.
 * 
 * @param list      The list.
 * @return void*    The last item in the list.
 */
void *List_Last(List_t list);

#endif // _LIST_H
