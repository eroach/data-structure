#include <stdlib.h>
#include <stdio.h>
#include "bst_tree.h"

bst_tree_t* bst_init()
{
    bst_tree_t* root;
    root = NULL;

    return root;
}

bst_tree_t* bst_create_node(int key, elem_t data)
{
    bst_tree_t* node;

    node = (bst_tree_t*)malloc(sizeof(bst_tree_t));
    if (node == NULL) {
        exit(1);
    }

    node->key = key;
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int bst_destroy(bst_tree_t** root)
{
    
    if ((*root) == NULL) {
        return RET_OK;
    }
   
    bst_destroy(&(*root)->left);
    bst_destroy(&(*root)->right);
    free(*root);
    (*root) = NULL;

    return RET_OK;
}

int bst_visit(bst_tree_t* root)
{
    printf("%d,", root->key);

    return RET_OK;
}

int bst_insert(bst_tree_t** root, bst_tree_t* node)
{
    if (node == NULL) {
        return RET_FAIL;
    }

    if ((*root) == NULL) {
        //printf("root:%d,", node->key);
        (*root) = node;
        return RET_OK;
    }

    if (node->key <= (*root)->key) {
        if ((*root)->left == NULL) {
            //printf("left:%d,", node->key);
            (*root)->left = node;
            node->parent = *root;
            return RET_OK;
        } else {
            return bst_insert(&((*root)->left), node);
        }
    } else {
        if ((*root)->right == NULL) {
            //printf("right:%d,", node->key);
            (*root)->right = node;
            node->parent = *root;
            return RET_OK;
        } else {
            return bst_insert(&((*root)->right), node);
        }
    }
}

int bst_preorder_traversal(bst_tree_t* root)
{
    if (root == NULL) {
        return RET_OK;
    }

    bst_visit(root);
    bst_preorder_traversal(root->left);
    bst_preorder_traversal(root->right);

    return RET_OK;
}

int bst_inorder_traversal(bst_tree_t* root)
{
    if (root == NULL) {
        return RET_OK;
    }

    bst_inorder_traversal(root->left);
    bst_visit(root);
    bst_inorder_traversal(root->right);

    return RET_OK;
}

int bst_postorder_traversal(bst_tree_t* root)
{
    if (root == NULL) {
        return RET_OK;
    }

    bst_postorder_traversal(root->left);
    bst_postorder_traversal(root->right);
    bst_visit(root);

    return RET_OK;
}

bst_tree_t* bst_search_by_key(bst_tree_t* root, int key)
{
    if ( root == NULL || root->key == key) {
        return root;
    }

    return root->key >key ? \
        bst_search_by_key(root->left, key): \
        bst_search_by_key(root->right, key);
}

int bst_max_depth(bst_tree_t* root)
{
    int ldepth = 0;
    int rdepth = 0;
    
    if (root == NULL) {
        return 0;
    }

    ldepth = 1 + bst_max_depth(root->left);
    rdepth = 1 + bst_max_depth(root->right);

    return ldepth > rdepth ? ldepth : rdepth;
}

int bst_delete_node(bst_tree_t** root, bst_tree_t* node)
{
    bst_delete_node_pre(root, node);

    free(node);
    node = NULL;

    return RET_OK;
}

int bst_delete_node_pre(bst_tree_t** root, bst_tree_t* node)
{
    bst_tree_t* child;

    if ((*root) == NULL || node == NULL) {
        return RET_FAIL;
    }

    if (node->left == NULL && node->right == NULL) {
        if (node->parent != NULL) {
            if (node->parent->left == node) {
                node->parent->left = NULL;
            } else {
                node->parent->right = NULL;
            }
        } else {
            (*root) = NULL;
        }

        return RET_OK;
    }

    if (node->left == NULL || node->right == NULL) {
        child = node->left ? node->left : node->right;
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = child;
            } else {
                node->parent->right = child;
            }
        } else {
            (*root) = child;
        }

        return RET_OK;
    }

    child = bst_successor(node);
    bst_delete_node_pre(root, child);

    if (node->parent) {
        if (node->parent->left == node) {
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
    } else {
        (*root) = child;
    }
    child->left = node->left;
    child->right = node->right;

    return RET_OK;
}

bst_tree_t* bst_successor(bst_tree_t* root)
{
    if (root->left == NULL) {
        return root;
    }

    return bst_successor(root->left);
}

