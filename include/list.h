#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include <stdio.h>

typedef struct int_list {
    int *data;
    size_t size;
    size_t capacity;
} int_list_t;

/**
 * Init and create the new int list collection
 * @param list The list collection
 * @param initialCapacity The initialize capacity of this list
 */
void list_init(int_list_t *list, size_t initialCapacity);

/**
 * Delete and free the int list collection
 * @param list The list collection
 */
void list_delete(int_list_t *list);

/**
 * Appends the specified element to the end of this list.
 * @param list  The list collection
 * @param element The int element
 */
void list_push(int_list_t *list, int element);

/**
 * Returns the element at the specified position in this list.
 * @param list The list collection
 * @param index  The index
 * @return Int element
 */
int list_get(const int_list_t *list, int index);

/**
 * Removes the element at the specified position in this list.
 * Shifts any subsequent elements to the left (subtracts one from their indices).
 * @param list The list collection
 * @param index  The index
 * @return Deleted element
 */
int list_remove(int_list_t *list, int index);

/**
 * Returns the number of elements in this list.
 * @param list The list collection
 * @return Size of collection
 */
int list_length(const int_list_t *list);

#endif //DATA_STRUCTURE_C_LIST_H