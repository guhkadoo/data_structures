#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))
#define largest(a, b) ((a) > (b) ? (a) : (b))

struct Node
{
    int value;
    struct Node *left, *right;
    short height;
};

struct Node *create_node(int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node != NULL) {
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        new_node->height = 0;
    } else {
        EXIT_WITH_ERROR("Error while allocating memory\n");
    }
    
    return new_node;
}

short height_node(struct Node *node)
{
    if(node == NULL)
        return -1;
    return node->height;
}

short balance_factor(struct Node *node)
{
    if(node)
        return (height_node(node->right) - height_node(node->left));
    return 0;
}

struct Node *leftRotation(struct Node *r)
{
    struct Node *a, *b;

    a = r->right;
    b = a->left;

    a->left = r;
    r->right = b;

    r->height = largest(height_node(r->left), height_node(r->right)) + 1;
    a->height = largest(height_node(a->left), height_node(a->right)) + 1;

    return a;
}

struct Node *rightRotation(struct Node *r)
{
    struct Node *a, *b;

    a = r->left;
    b = a->right;

    a->right = r;
    r->left = b;

    r->height = largest(height_node(r->left), height_node(r->right)) + 1;
    a->height = largest(height_node(a->left), height_node(a->right)) + 1;
    
    return a;
}

struct Node *rightLeftRotation(struct Node *r)
{
    r->right = rightRotation(r->right);
    return leftRotation(r);
}

struct Node *leftRightRotation(struct Node *r)
{
    r->left = leftRotation(r->left);
    return rightRotation(r);
}

struct Node *balance(struct Node *r)
{
    if(balance_factor(r) > 1 && balance_factor(r->right) >= 0) {
        r = leftRotation(r);
    } else if(balance_factor(r) > 1 && balance_factor(r->right) < 0) {
        r = rightLeftRotation(r);
    } else if(balance_factor(r) < -1 && balance_factor(r->left) <= 0) {
        r = rightRotation(r);
    } else if(balance_factor(r) < -1 && balance_factor(r->left) > 0) {
        r = leftRightRotation(r);
    }
    return r;
}

struct Node *insert(struct Node *r, int value)
{
    if(r == NULL) {
        return create_node(value);
    } else {
        if(value > r->value)
            r->right = insert(r->right, value);
        else if(value < r->value)
            r->left = insert(r->left, value);

        r->height = largest(height_node(r->left), height_node(r->right)) + 1;

        r = balance(r);
    }

    return r;
}

struct Node *remove_node(struct Node *tree, int value)
{
    if(tree != NULL) {
        if(tree->value == value) {
            if(tree->right == NULL && tree->left == NULL) {
                free(tree);
                return NULL;
            } else if(tree->right != NULL && tree->left != NULL) {
                struct Node *aux = tree->left;
                while(aux->right != NULL)
                    aux = aux->right;
                tree->value = aux->value;
                aux->value = value;
                tree->left = remove_node(tree->left, value); 
                return tree;
            } else {
                struct Node *aux;
                if(tree->right != NULL)
                    aux = tree->right;
                else
                    aux = tree->left;
                free(tree);
                return aux;
            }
        } else {
            if(value > tree->value)
                tree->right = remove_node(tree->right, value);
            else if(value < tree->value)
                tree->left = remove_node(tree->left, value);
        }
        tree->height = largest(height_node(tree->left), height_node(tree->right)) + 1;
        tree = balance(tree);

        return tree;
    }
    return NULL;
}

void dfs_preorder(struct Node *tree)
{
    if(tree != NULL) {
        printf("%d ", tree->value);
        dfs_preorder(tree->left);
        dfs_preorder(tree->right);
    }
}

void dfs_inorder(struct Node *tree)
{
    if(tree != NULL) {
        dfs_preorder(tree->left);
        printf("%d ", tree->value);
        dfs_preorder(tree->right);
    }
}

void dfs_postorder(struct Node *tree)
{
    if(tree != NULL) {
        dfs_preorder(tree->left);
        dfs_preorder(tree->right);
        printf("%d ", tree->value);
    }
}

void print_avl(struct Node *tree, int layer)
{
    if(tree) {
        print_avl(tree->right, layer+1);
        printf("\n\n");
        for(int i=0; i<layer; i++)
            printf("\t");
        printf("%d", tree->value);
        print_avl(tree->left, layer+1);
    }
}

#endif //AVL_H
