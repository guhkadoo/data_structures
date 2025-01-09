#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Node 
{
    int value;
    struct Node *right, *left;
};

struct Queue {
    struct Queue *next;
    struct Node *node;
};

void enqueue(struct Queue **queue, struct Node *node)
{
    struct Queue *new_node = (struct Queue*)malloc(sizeof(struct Queue));
    if(new_node) {
        new_node->next = NULL;
        new_node->node = node;
        if(*queue == NULL) {
            *queue = new_node;
        } else {
            struct Queue *aux = *queue;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = new_node;
        }
    } else {
        EXIT_WITH_ERROR("Error while allocating memory...");
    }
}

struct Queue *dequeue(struct Queue **queue)
{
    struct Queue *remove = *queue;
    if(remove != NULL) {
        *queue = remove->next;
    }
    return remove;
}

struct Node *insert(struct Node *tree, int value)
{
    if(tree == NULL) {
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->right = new_node->left = NULL;
        return new_node;
    } else if(value > tree->value) {
        tree->right = insert(tree->right, value);
    } else if(value < tree->value) {
        tree->left = insert(tree->left, value);
    }
    return tree;
}

void insert_void(struct Node **tree, int value)
{
    if(*tree == NULL) {
        *tree = (struct Node*)malloc(sizeof(struct Node));
        (*tree)->value = value;
        (*tree)->right = (*tree)->left = NULL;
    } else if(value > (*tree)->value) {
        insert_void(&(*tree)->right, value);
    } else if(value < (*tree)->value) {
        insert_void(&(*tree)->left, value);
    }
}

void insert_no_recursion(struct Node **tree, int value)
{
    struct Node *aux = *tree;
    while(aux) {
        if(value < aux->value) {
            tree = &aux->left;
        } else if(value > aux->value) {
            tree = &aux->right;
        }
        aux = *tree;
    }
    aux = (struct Node*)malloc(sizeof(struct Node));
    aux->value = value;
    aux->left = aux->right = NULL;
    *tree = aux;
}

void dfs_inorder(struct Node *tree)
{
    if(tree == NULL)
        return ;
    dfs_inorder(tree->left);
    printf("%d ", tree->value);
    dfs_inorder(tree->right);
}

void dfs_preorder(struct Node *tree)
{
    if(tree == NULL)
        return ;
    printf("%d ", tree->value);
    dfs_preorder(tree->left);
    dfs_preorder(tree->right);
}

void dfs_postorder(struct Node *tree)
{
    if(tree == NULL)
        return ;
    dfs_postorder(tree->left);
    dfs_postorder(tree->right);
    printf("%d ", tree->value);
}

void bfs(struct Node *tree)
{
    struct Queue *queue = NULL;
    if(tree != NULL) {
        enqueue(&queue, tree);
        while(queue != NULL) {
            struct Queue *aux = dequeue(&queue);
            printf("%d ", aux->node->value);
            if(aux->node->left != NULL)
                enqueue(&queue, aux->node->left);
            if(aux->node->right != NULL) {
                enqueue(&queue, aux->node->right);
            }
            free(aux);
        }
    }
}

struct Node *search(struct Node *tree, int value)
{
    if(tree != NULL) {
        if(tree->value == value)
            return tree;
        else if(value > tree->value)
            search(tree->right, value);
        else
            search(tree->left, value);
    } 
    return NULL;
}

struct Node *search_no_recursion(struct Node *tree, int value)
{
    while(tree != NULL && tree->value != value) {
        if(value > tree->value) {
            tree = tree->right;
        } else if(value < tree->value) {
            tree = tree->left;
        }
    }
    return tree;
}

void remove_node(struct Node **tree, int value)
{
    if(*tree != NULL) {
        struct Node *aux = *tree;
        struct Node *previous = *tree;
        while(aux && aux->value != value) {
            if(value > aux->value) {
                tree = &aux->right;
            } else if(value < aux->value) {
                tree = &aux->left;
            }
            previous = aux;
            aux = *tree;
        }
        if(aux != NULL) {
            if(aux->left == NULL && aux->right == NULL) {
                if(value > previous->value)
                    previous->right = NULL;
                else if(value < previous->value)
                    previous->left = NULL;
                if(aux == previous) // this is the case of only one node!
                    *tree = NULL;
                free(aux);
            } else if(aux->left != NULL && aux->right != NULL) {
                struct Node *to_be_removed = aux->left;
                struct Node *previous_to_be_removed = aux;
                while(to_be_removed->right != NULL) {
                    previous_to_be_removed = to_be_removed;
                    to_be_removed = to_be_removed->right;
                }
                aux->value = to_be_removed->value;
                if(previous_to_be_removed == aux) // there is only one node left to aux (aux->left height is 0)
                    previous_to_be_removed->left = NULL; 
                else // aux->left height > 0 
                    previous_to_be_removed->right = NULL;
                free(to_be_removed); // we remove the leaf node
            } else {
                struct Node *next_node;
                if(aux->left != NULL)
                    next_node = aux->left;
                else
                    next_node = aux->right;
                if(next_node->value > previous->value)
                    previous->right = next_node;
                else
                    previous->left = next_node;
                free(aux);
            }
        }
    }
}

int height(struct Node *tree)
{
    if(tree == NULL)
        return -1;
    else {
        int left = height(tree->left);
        int right = height(tree->right);
        if(left > right)
            return left + 1;
        else
            return right + 1;
    }
}

int number_of_nodes(struct Node *tree)
{
    if(tree == NULL)
        return 0;
    return 1 + number_of_nodes(tree->left) + number_of_nodes(tree->right);
}

int number_of_leaves(struct Node *tree)
{
    if(tree && tree->left == NULL && tree->right == NULL)
        return 1;
    if(tree == NULL)
        return 0;
    return number_of_leaves(tree->left) + number_of_leaves(tree->right);
}


#endif //BINARY_TREE_H
