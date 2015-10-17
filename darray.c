#include "darray.h"
#include <stdlib.h>

d_array_t* darray_create()
{
    int i=0;
    d_array_t* darray = (d_array_t*)malloc(sizeof(d_array_t));

    if(darray != NULL) 
    {
        darray->count = 0;
        darray->size = 0;
        darray->data = (void**)malloc(sizeof(void*)*DEFAULT_ARRAY_SIZE);

        if(darray->data != NULL)
        {
            darray->size = DEFAULT_ARRAY_SIZE;
            for(i=0; i<darray->size; i++)
            {
                darray->data[i] = NULL;
            }
        }

        return darray;
    }

    return NULL;
}

int darray_expand(d_array_t* darray, int expand_size)
{
    int new_size;

    new_size = (expand_size == 0) ? 2*darray->size : \
               darray->size+expand_size;

    void** data = (void**)realloc(darray->data, sizeof(void*)*new_size);

    if(data == NULL)
    {
        return RET_FAIL;
    }

    darray->data = data;
    darray->size = new_size;

    return RET_OK;
}

int darray_destroy(d_array_t** darray)
{
    if(*darray == NULL)
    {
        return RET_FAIL;
    }

    if((*darray)->data != NULL)
    {
        free((*darray)->data);
        (*darray)->data = NULL;
    }
    free(*darray);
    *darray = NULL;

    return RET_OK;
}

int darray_append(d_array_t* darray, void* data)
{
    if(darray == NULL)
    {
        return RET_FAIL;
    }

    if(darray->count == darray->size)
    {
        darray_expand(darray, 0);
    }
    darray->data[darray->count] = data;
    darray->count++;

    return RET_OK;
}

int darray_set_by_index(d_array_t* darray, int index, void* data)
{
    if(darray == NULL || index<0 || index>=darray->count)
    {
        return RET_FAIL;
    }

    darray->data[index] = data;

    return RET_OK;
}

int darray_insert(d_array_t* darray, int index, void* data)
{
    if(darray == NULL || index<0 || index>=darray->count)
    {
        return RET_FAIL;
    }

    if(darray->count == darray->size)
    {
        darray_expand(darray, 0);
    }

    for(i=darray->count; i>index; i--)
    {
        darray->data[i] = darray->data[i-1];
    }
    darray->data[index] = *data;
    darray->count++;

    return RET_OK;
}

int darray_delete(d_array_t* darray, int index)
{
    int i;
    
    if(darray == NULL || index<0 || index>=darray->count)
    {
        return RET_FAIL;
    }

    for(i=index; i<darray->count-1; i++)
    {
        darray->data[index] = darray->data[index+1];
    }
    darray->count--;

    return RET_OK;
}

int darray_get_count(d_array_t* darray)
{
    if(darray == NULL)
    {
        return 0;
    }

    return darray->count;
}

int darray_get_size(d_array_t* darray)
{
    if(darray == NULL)
    {
        return 0;
    }

    return darray->size;
}

void* darray_get_by_index(d_array_t* darray, int index)
{
    if(darray == NULL)
    {
        return NULL;
    }

    return darray->data[index];
}
