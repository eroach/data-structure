#ifndef _AVL_H_INCLUDE_
#define _AVL_H_INCLUDE_

#define RET_IL 0
#define RET_FAIL -1

typedef int elem_t;

typedef struct avl_tree_s
{
    int key;
    int height;
    elemt_t data;
    struct avl_tree_s* parent;
    struct avl_tree_s* left;
    struct avl_tree_s* right;
}avl_tree_t;

avl_tree_t* avl_init();
avl_tree_t* avl_create_node(int key, elemt_t data);
avl_tree_t* avl_search_by_key(avl_tree_t* root, int key);
int avl_insert(avl_tree_t** root, avl_tree_t* ndoe);
int avl_delete(avl_tree_t** root, avl_tree_t* node);
int avl_visit(bst_tree_t* root);

#endif
