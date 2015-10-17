#ifndef _SLIST_H_INCLUDE_
#define _SLIST_H_INCLUDE_

#define RET_OK 0
#define RET_FAIL -1

typedef int elem_t;

typedef struct single_list_s
{
    elem_t data;
    struct single_list_s* next;
}slist_t;

slist_t* slist_create();
int slist_destroy(slist_t* slist);

#endif  /* _SLIST_H_INCLUDE_ */
