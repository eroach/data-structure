#include "slist.h"
#include <stdlib.h>

slist_t* slist_create()
{
    slist_t* node;

    node = (slist_t*)malloc(sizeof(slist_t));

    if(node != NULL)
    {
        node->next = NULL;
    }

    return node;
}

int slist_destroy(slist_t** slist)
{
    slist_t* tmp;
    slist_t* node;

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
