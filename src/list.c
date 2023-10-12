#include <stdio.h>
#include <stdlib.h>

typedef struct int_list
{
    int* elements;
    size_t capacity;
    size_t size;
} int_list_t;
void list_init(int_list_t* list, size_t initialCapacity)
{
    list->elements = (int*)malloc(initialCapacity * sizeof(int));
    list->capacity = initialCapacity;
    list->size = 0;
}
void list_delete(int_list_t* list)
{
    free(list->elements);
    list->elements = NULL;
    list->capacity = 0;
    list->size = 0;
}

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

int list_get(const int_list_t* list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->elements[index];
    }

    printf("Error: Index out of bounds.\n");
    return -1;
}

int list_remove(int_list_t* list, int index)
{
    if (index >= 0 && index < list->size)
    {
        int removedElement = list->elements[index];
        for (size_t i = index; i < list->size - 1; i++)
        {
            list->elements[i] = list->elements[i + 1];
        }
        list->size--;
        return removedElement;
    }

    printf("Error: Index out of bounds.\n");
    return -1;
}

int list_length(const int_list_t* list)
{
    return list->size;
}

int main()
{
    int_list_t list;
    list_init(&list, 10);

    // 添加元素到列表
    list_push(&list, 5);
    list_push(&list, 10);
    list_push(&list, 15);

    // 获取列表的长度
    int length = list_length(&list);
    printf("List length: %d\n", length);

    // 获取和移除列表中的元素
    int element = list_get(&list, 1);
    printf("Element at index 1: %d\n", element);

    int removedElement = list_remove(&list, 0);
    printf("Removed element at index 0: %d\n", removedElement);

    // 最终列表的长度
    length = list_length(&list);
    printf("List length after removal: %d\n", length);

    // 释放列表内存
    list_delete(&list);

    return 0;
}
