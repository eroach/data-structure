#ifndef _DLIST_H_INCLUDE_
#define _DLIST_H_INCLUDE_

#define RET_OK 0
#define RET_FAIL -1

typedef int elem_t;

typedef struct double_node_s {
    elem_t data;
    struct double_node_s* prior;
    struct double_node_s* next;
}d_node_t;

typedef struct double_list_s {
    int length;
    d_node_t* head;
    d_node_t* tail;
}d_list_t;

d_list_t* dlist_create();

int dlist_traversal(d_list_t* dlist);
int dlist_clear(d_list_t* dlist);
int dlist_destroy(d_list_t* dlist);
int dlist_check(d_list_t* dlist);

int dlist_insert_head(d_list_t* dlist, elem_t data);
int dlist_insert_tail(d_list_t* dlist, elem_t data);
int dlist_insert_by_index(d_list_t* dlist, int index, elem_t data);

int dlist_delete_head(d_list_t* dlist);
int dlist_delete_tail(d_list_t* dlist);
int dlist_delete_by_index(d_list_t* dlist, int index);

int dlist_sort(d_list_t* dlist);
int dlist_reserve(d_list_t* dlist);

elem_t dlist_get_head(d_list_t* dlist);
elem_t dlist_get_tail(d_list_t* dlist);
elem_t dlist_get_by_index(d_list_t* dlist, int index);

#endif
