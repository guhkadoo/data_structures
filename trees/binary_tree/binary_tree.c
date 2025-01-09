#include "binary_tree.h"

int main(int argc, char *argv[])
{
    struct Node *tree = NULL;
    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 15);
    tree = insert(tree, 16);
    tree = insert(tree, 17);
    tree = insert(tree, 30);
    tree = insert(tree, 5);
    tree = insert(tree, 4);
    tree = insert(tree, 3);
    tree = insert(tree, 14);
    /*dfs_inorder(tree);
    printf("\n");
    dfs_preorder(tree);
    printf("\n");
    dfs_postorder(tree);
    printf("\n");*/
    bfs(tree);

    printf("\nnumber of nodes: %d\n", number_of_nodes(tree));
    printf("number of leaf nodes: %d\n", number_of_leaves(tree));
    printf("Height of the tree: %d\n", height(tree));

    struct Node * aux = search_no_recursion(tree, 30);
    if(aux != NULL) {
        printf("Elemento encontrado!\n");
    }

    remove_node(&tree, 20);
    remove_node(&tree, 10);
    bfs(tree);
}
