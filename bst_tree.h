#ifndef _BST_TREE_H_INCLUDE_
#define _BST_TREE_H_INCLUDE_

#define RET_OK 0
#define RET_FAIL -1 

typedef int elem_t;

typedef struct bst_tree_s
{
    int key;
    elem_t data;
    struct bst_tree_s* parent;
    struct bst_tree_s* left;
    struct bst_tree_s* right;
}bst_tree_t;

bst_tree_t* bst_init();
bst_tree_t* bst_create_node(int key, elem_t data);
bst_tree_t* bst_search_by_key(bst_tree_t* root, int key);
bst_tree_t* bst_successor(bst_tree_t* root);
int bst_destroy(bst_tree_t** root);
int bst_max_depth(bst_tree_t* root);
int bst_visit(bst_tree_t* root);
int bst_insert(bst_tree_t** root, bst_tree_t* node);
int bst_delete_node(bst_tree_t** root, bst_tree_t* node);
int bst_delete_node_pre(bst_tree_t** root, bst_tree_t* node);
int bst_preorder_traversal(bst_tree_t* root);
int bst_inorder_traversal(bst_tree_t* root);
int bst_postorder_traversal(bst_tree_t* root);

#endif
