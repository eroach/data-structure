#include <stdio.h>
#include <stdlib.h>
#include "bst_tree.c"

#define N 5

int main() {
    bst_tree_t* root;
    bst_tree_t* node;
    int i;
    int elem[N] = {3,1,5,2,4};

    root = bst_init();
   
    for (i=0; i<N; i++) {
        node = bst_create_node(elem[i], elem[i]);
        bst_insert(&root, node);
    }

    /*
    printf("%d\n", root->key);
    printf("%d\n", root->left->parent->key);
    printf("%d\n", root->left->right->parent->key);
    printf("%d\n", root->right->parent->key);
    printf("%d\n", root->right->left->parent->key);
    */

    //bst_destroy(&root);
    node = bst_search_by_key(root, 1);
    //node = bst_successor(root->right);
    //printf("\n\n%d\n", node->key);

    bst_delete_node(&root, node);

    bst_preorder_traversal(root);
    puts("\n");
    bst_inorder_traversal(root);
    puts("\n");
    bst_postorder_traversal(root);

    //printf("%d\n", bst_max_depth(root));
    

    return RET_OK;

}
