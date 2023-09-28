#include <criterion/criterion.h>
#include <list.h>

Test(list_test, test) {
    int_list_t *list = malloc(sizeof(int_list_t));
    // Init list
    list_init(list, 5);
    list_push(list, 1);
    list_push(list, 2);
    list_push(list, 3);
    cr_assert_eq(list_get(list, 0), 1);
    cr_assert_eq(list_get(list, 1), 2);
    cr_assert_eq(list_get(list, 2), 3);
    cr_assert_eq(list_length(list), 3);
    // Remove head
    list_remove(list, 0);
    cr_assert_eq(list_get(list, 0), 2);
    cr_assert_eq(list_get(list, 1), 3);
    cr_assert_eq(list_length(list), 2);
    // Remove tail
    list_remove(list, 1);
    cr_assert_eq(list_get(list, 0), 2);
    cr_assert_eq(list_length(list), 1);
    // cleanup the list
    list_delete(list);
    cr_assert_eq(list->data, NULL);
    cr_assert_eq(list_length(list), 0);
    free(list);
}