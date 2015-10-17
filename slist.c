#include "slist.h"
#include <stdlib.h>

s_list_t* slist_create()
{
    s_list_t* node;

    node = (s_list_t*)malloc(sizeof(s_list_t));

    if(node != NULL)
    {
        node->next = NULL;
    }

    return node;
}

int slist_destroy(s_list_t** slist)
{
    s_list_t* tmp;
    s_list_t* node;

    node = (*slist)->next;
    free(*slist);

    while(node)
    {
        tmp = node->next;
        free(node);
        node = tmp;
    }

    return RET_OK;
}

int slist_append(s_list_t* slist, elem_t data)
{
    s_list_t* node;

    if(slist == NULL)
    {
        return RET_FAIL;
    }

    while(slist->next)
    {
        slist = slist->next;
    }

    node = (s_list_t*)malloc(sizeof(s_list_t));
    if(node == NULL)
    {
        return RET_FAIL;
    }

    node->data = data;
    node->next = NULL;
    slist->next = node;

    return RET_OK;
}

elem_t slist_get_by_index(s_list_t* slist, int index)
{
    int i;
    s_list_t* node;

    for(i=0; i<=index; i++)
    {
        node = slist;
        if(slist != NULL)
        {
            slist = slist->next;
        }
    }

    return node->data;
}
