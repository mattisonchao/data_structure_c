#include <stdio.h>
#include <stdlib.h>

typedef struct int_list  //typedef为整个int_list的结构体定义了一个新名称int_list_t
{
    int* elements;       //指针变量elements指向整型数组➡️用于存储列表中的元素
                         //注意:elements是一个数组(访问数组中的第一个元素用elements[0])
                         //用指针可以动态分配内存以适应列表的大小变化,就不需要提前确定列表的长度
    size_t capacity;     //定义一个无符号整型capacity➡️当前分配的内存空间可以容纳的元素数量的上限
    size_t size;         //定义一个无符号整型size变量➡️表示当前存储的元素数量
} int_list_t;            //新名称➡️代码中用int_list_t表示整型数据列表

void list_init(int_list_t* list, size_t initialCapacity)  //定义一个无返回值类型的list_init函数➡️用于初始化列表
                                                          // 接收指向int_list_t类型的指针变量list为参数;
                                                          // 另一个参数是无符号整型类型的变量initialCapacity➡️初始容量
{
    list->elements = (int*)malloc(initialCapacity * sizeof(int));//
    list->capacity = initialCapacity;
    list->size = 0;
}                                          //以上为函数体

void list_delete(int_list_t* list)      //定义一个无返回值类型的函数list_delete
                                        //接收的参数为指向int_list_t自定义结构体类型的指针变量list
{
    free(list->elements);
    list->elements = NULL;
    list->capacity = 0;
    list->size = 0;
}

void list_push(int_list_t* list, int element)  //定义一个无返回值类型的函数list_push
       //接收参数:1.指向int_list_t类型的指针变量list;
       //       2.整型变量element
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

int main()                                    //程序入口
{
    int_list_t list;                          //声明int_list_t类型的变量list
    list_init(&list, 10);         //调用list_init函数,将list的地址作为参数传递出去

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
