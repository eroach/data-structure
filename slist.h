#ifndef _SLIST_H_INCLUDE_
#define _SLIST_H_INCLUDE_

#define RET_OK 0
#define RET_FAIL -1

typedef int elem_t;

typedef struct single_list_s
{
    elem_t data;
    struct single_list_s* next;
}s_list_t;

s_list_t* slist_create();
int slist_destroy(s_list_t** slist);
int slist_append(s_list_t* slist, elem_t data);
elem_t slist_get_by_index(s_list_t* slist, int index);

#endif  /* _SLIST_H_INCLUDE_ */
