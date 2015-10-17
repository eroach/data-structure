#ifndef _DARRAY_H_INCLUDE_
#define _DARRAY_H_INCLUDE_

#define DEFAULT_ARRAY_SIZE 16
#define RET_OK 0
#define RET_FAIL -1

typedef struct dynamic_array_s
{
    int size;
    int count;
    void** data;
}d_array_t;

d_array_t* darray_create();
int darray_expand(d_array_t* darray, int expand_size);
int darray_destroy(d_array_t** darray);
int darray_append(d_array_t* darray, void* data);
int darray_set_by_index(d_array_t* darray, int index, void* data);
void* darray_get_by_index(d_array_t* darray, int index);
int darray_insert(d_array_t* darray, int index, void* data);
int darray_delete(d_array_t* darray, int index);
int darray_get_count(d_array_t* darray);
int darray_get_size(d_array_t* darray);

#endif  /* _DARRAY_H_INCLUDE_ */

