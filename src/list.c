#include <list.h>
#include <stdlib.h>

void list_init(int_list_t *list, size_t initialCapacity) {
    list->data = (int *) malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
}

void list_delete(int_list_t *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void list_push(int_list_t *list, int element) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *) realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = element;
}

int list_get(const int_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

int list_remove(int_list_t *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    int element = list->data[index];
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;

    // If size is significantly smaller than capacity, shrink the array
    if (list->size <= list->capacity / 4) {
        list->capacity /= 2;
        list->data = (int *) realloc(list->data, list->capacity * sizeof(int));
    }

    return element;
}

int list_length(const int_list_t *list) {
    return list->size;
}
