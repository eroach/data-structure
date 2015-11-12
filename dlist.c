#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

d_list_t* dlist_create()
{
    d_list_t* dlist;

    dlist = (d_list_t*)malloc(sizeof(d_list_t));
    dlist->length = 0;
    dlist->head = NULL;
    dlist->tail = NULL;
    
    return dlist;
}

int dlist_clear(d_list_t* dlist)
{
    d_node_t* tmp;
    d_node_t* node;

    node = dlist->head;
    dlist->head = NULL;
    dlist->length = 0;

    while (node) {
        printf("%d,", node->data);
        tmp = node->next;
        free(node);
        node = tmp;
    }

    return RET_OK;
}

int dlist_destroy(d_list_t* dlist)
{
    dlist_clear(dlist);

    free(dlist);
    
    return RET_OK;
}

int dlist_check(d_list_t* dlist)
{
    if (!dlist->head || !dlist->tail) {
        return RET_FAIL;
    } else {
        return RET_OK;
    }
}

int dlist_insert_tail(d_list_t* dlist, elem_t data)
{
    d_node_t* tmp;
    d_node_t* node;

    node = (d_node_t*)malloc(sizeof(d_node_t));
    
    if (!node) {
        return RET_FAIL;
    }

    node->data = data;
    tmp = dlist->tail;
    dlist->tail = node;
    node->next = NULL;
    node->prior = tmp;

    if (!tmp) {
        dlist->head = node;
    } else {
        tmp->next = node;
    }

    dlist->length++;

    return RET_OK;
}


int dlist_insert_head(d_list_t* dlist, elem_t data)
{
    d_node_t* tmp;
    d_node_t* node;

    node = (d_node_t*)malloc(sizeof(d_node_t));
    
    if (!node) {
        return RET_FAIL;
    }

    node->data = data;
    
    tmp = dlist->head;
    dlist->head = node;
    node->prior = NULL;
    node->next = tmp;

    if (!tmp) {
        dlist->tail = node;
    } else {
        tmp->prior = node;
    }

    dlist->length++;

    return RET_OK;
}

int dlist_insert_by_index(d_list_t* dlist, int index, elem_t data)
{
    int i = 0;
    d_node_t* tmp;
    d_node_t* node;
    int len = dlist->length;

    if (index == 0) {
        return dlist_insert_head(dlist, data);
    } else if (index == len) {
        return dlist_insert_tail(dlist, data);
    }

    tmp = dlist->head;

    while (tmp && i<index) {
        tmp = tmp->next;
        i++;
    }
   
    node = (d_node_t*)malloc(sizeof(d_node_t));

    if (!node) {
        return RET_FAIL;
    }
    node->data = data;

    node->next = tmp->next;
    node->prior = tmp;
    tmp->next->prior = node;    
    tmp->next = node;
    dlist->length++;

    return RET_OK;
}

int dlist_delete_head(d_list_t* dlist)
{
    d_node_t* node;
    
    if (!dlist->head) {
        return RET_OK;
    }

    node = dlist->head;
    dlist->length--;

    if (!node->next) {
        dlist->tail = NULL;
        free(node);
        return RET_OK;
    }

    dlist->head = node->next;

    node->next->prior = NULL;
    node->next = NULL;
    free(node);

    return RET_OK;
}

int dlist_delete_tail(d_list_t* dlist)
{
    d_node_t* node;
    
    if (!dlist->head) {
        return RET_OK;
    }

    node = dlist->tail;
    dlist->length--;

    if (!node->prior) {
        dlist->head = NULL;
        free(node);
        return RET_OK;
    }

    dlist->tail = node->prior;

    node->prior->next = NULL;
    node->prior= NULL;
    free(node);

    return RET_OK;
}

int dlist_delete_by_index(d_list_t* dlist, int index)
{
    int i = 1;
    d_node_t* node;

    if (index < 1 || index > dlist->length) {
        return RET_FAIL;
    }

    if (index == 1) {
        dlist_delete_head(dlist);
        return RET_OK;
    } else if (index == dlist->length) {
        dlist_delete_tail(dlist);
        return RET_OK;
    }

    node = dlist->head;

    while (i<index) {
        node = node->next;
        i++;
    }

    node->prior->next = node->next;
    node->next->prior = node->prior;
    free(node);
    dlist->length--;

    return RET_OK;
}

elem_t dlist_get_head(d_list_t* dlist)
{
    if (!dlist->head) {
        exit(1);
    }

    return dlist->head->data;
}

elem_t dlist_get_tail(d_list_t* dlist)
{
    if (!dlist->head) {
        exit(1);
    }

    return dlist->tail->data;
}

elem_t dlist_get_by_index(d_list_t* dlist, int index)
{
    int i=1;
    d_node_t* tmp;

    if (index < 1 || index > dlist->length) {
        exit(1);
    }

    if (index == 1) {
        dlist_get_head(dlist);
    } else if (index == dlist->length) {
        dlist_get_tail(dlist);
    }

    tmp = dlist->head;
    while (i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp->data;
}

int dlist_traversal(d_list_t* dlist)
{
    d_node_t* tmp;

    tmp = dlist->head;

    if (!tmp) {
        printf("Empty List\n");
        return RET_OK;
    }

    while (tmp) {
        printf("%d,", tmp->data);
        tmp = tmp->next;
    }

    return RET_OK;
}

