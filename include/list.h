#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct int_list
{
    int* elements;    // Pointer to the array of elements
    size_t capacity;  // Capacity of the list
    size_t size;      // Current number of elements in the list
} int_list_t;

/**
 * Init and create a new int list collection.
 * @param list The list collection
 * @param initialCapacity The initial capacity of this list
 */
void list_init(int_list_t* list, size_t initialCapacity)
{
    list->elements = (int*)malloc(initialCapacity * sizeof(int));
    list->capacity = initialCapacity;
    list->size = 0;
}

/**
 * Delete and free the int list collection.
 * @param list The list collection
 */
void list_delete(int_list_t* list)
{
    free(list->elements);
    list->capacity = 0;
    list->size = 0;
}

/**
 * Appends the specified element to the end of this list.
 * @param list The list collection
 * @param element The int element
 */
void list_push(int_list_t* list, int element)
{
    if (list->size >= list->capacity)
    {
        size_t newCapacity = list->capacity * 2;
        list->elements = (int*)realloc(list->elements, newCapacity * sizeof(int));
        list->capacity = newCapacity;
    }

    list->elements[list->size] = element;
    list->size++;
}

/**
 * Returns the element at the specified position in this list.
 * @param list The list collection
 * @param index The index
 * @return Int element
 */
int list_get(const int_list_t* list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->elements[index];
    }

    // Handle out-of-bounds index
    printf("Error: Index out of bounds.\n");
    return -1;  // Or use error handling mechanism of your choice
}

/**
 * Removes the element at the specified position in this list.
 * Shifts any subsequent elements to the left (subtracts one from their indices).
 * @param list The list collection
 * @param index The index
 * @return Deleted element
 */
int list_remove(int_list_t* list, int index)
{
    if (index >= 0 && index < list->size)
    {
        int element = list->elements[index];
        for (int i = index; i < list->size - 1; i++)
        {
            list->elements[i] = list->elements[i + 1];
        }
        list->size--;

        return element;
    }

    // Handle out-of-bounds index
    printf("Error: Index out of bounds.\n");
    return -1;  // Or use error handling mechanism of your choice
}

/**
 * Returns the number of elements in this list.
 * @param list The list collection
 * @return Size of collection
 */
int list_length(const int_list_t* list)
{
    return list->size;
}

#endif //DATA_STRUCTURE_C_LIST_H
