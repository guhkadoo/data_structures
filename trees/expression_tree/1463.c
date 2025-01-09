#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// BEECROWD EXERCISE 1463

struct Tree_node
{
    char value;
    int level;
    struct Tree_node *left;
    struct Tree_node *right;
};

struct List_node
{
    struct Tree_node *tree_node;
    struct List_node *next;
};

void append(struct List_node **list, char value)
{
    // creation of list_node->tree_node;
    struct Tree_node *tree_node = (struct Tree_node *)malloc(sizeof(struct Tree_node));
    tree_node->value = value;
    tree_node->left = tree_node->right = NULL;

    // creation of list_node which is gonna be appended
    struct List_node *new_list_node = (struct List_node *)malloc(sizeof(struct List_node));
    new_list_node->tree_node = tree_node;
    new_list_node->next = NULL;


    if(*list == NULL) { // if list is empty
        *list = new_list_node; 
    } else { // if list has one or more elements -> go to the last and append the new one
        struct List_node *aux = *list;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_list_node;
    }
}

struct List_node *pop(struct List_node **list)
{
    struct List_node *remove = NULL;
    if(*list != NULL) {
        remove = *list;
        *list = remove->next;
    }
    return remove;
}

void push(struct List_node **list, char value)
{
    // creation of list_node->tree_node;
    struct Tree_node *tree_node = (struct Tree_node *)malloc(sizeof(struct Tree_node));
    tree_node->value = value;
    tree_node->left = tree_node->right = NULL;

    // creation of list_node which is gonna be appended
    struct List_node *new_list_node = (struct List_node *)malloc(sizeof(struct List_node));
    new_list_node->tree_node = tree_node;
    new_list_node->next = NULL;

    new_list_node->next = *list;
    *list = new_list_node;
}

int has_higher_precedence(char operator_1, char operator_2)
{
    if(operator_1 == '*' || operator_1 == '/') {
        if(operator_2 == '+' || operator_2 == '-') return 1;
    }
    return 0;
}

int is_operand(char character)
{
    if((character >= '0' && character <='9') || (character >='a' && character <= 'z') || (character >='A' && character <='Z'))
        return 1;
    return 0;
}

int is_operator(char character)
{
    if(character == '+' || character == '-' || character == '*' || character == '/')
        return 1;
    return 0;
}

void print_stack(struct List_node *stack)
{
    while(stack != NULL) {
        printf("%c, ", stack->tree_node->value);
        stack = stack->next;
    }
}

struct List_node *infix_to_postfix(char infix_expression[])
{
    struct List_node *operator_stack = NULL;
    struct List_node *postfix_queue = NULL;
    
    for(int i=0; infix_expression[i]!='\0'; i++){
        if(is_operand(infix_expression[i])){ 
            append(&postfix_queue, infix_expression[i]);
        } else if(is_operator(infix_expression[i])){
            if(operator_stack == NULL || operator_stack->tree_node->value == '(' || has_higher_precedence(infix_expression[i], operator_stack->tree_node->value)) push(&operator_stack, infix_expression[i]);
            else {
                while(operator_stack != NULL && operator_stack->tree_node->value != '(' && !has_higher_precedence(infix_expression[i], operator_stack->tree_node->value)) {
                    struct List_node *aux = pop(&operator_stack);
                    append(&postfix_queue, aux->tree_node->value);
                    free(aux);
                }
                push(&operator_stack, infix_expression[i]);
            }
        } else if(infix_expression[i] == '(') {
            push(&operator_stack, infix_expression[i]);
        } else if(infix_expression[i] == ')') {
            while(operator_stack->tree_node->value != '(') {
                struct List_node *aux = pop(&operator_stack);
                append(&postfix_queue, aux->tree_node->value);
                free(aux);
            }
            free(pop(&operator_stack));
        }
    }
    while(operator_stack != NULL) {
        struct List_node *aux = pop(&operator_stack);
        append(&postfix_queue, aux->tree_node->value);
        free(aux);
    }
    return postfix_queue;
}

struct Tree_node *binary_expression_tree(struct List_node *postfix_queue)
{
    struct List_node *expression_tree_stack = NULL;
    while(postfix_queue != NULL)
    {
        if(is_operand(postfix_queue->tree_node->value)) {
            push(&expression_tree_stack, postfix_queue->tree_node->value);
        } else {
            struct List_node *aux_1 = pop(&expression_tree_stack);
            struct List_node *aux_2 = pop(&expression_tree_stack);

            // creation of list_node->tree_node;
            struct Tree_node *tree_node = (struct Tree_node *)malloc(sizeof(struct Tree_node));
            tree_node->value = postfix_queue->tree_node->value;
            tree_node->right = aux_1->tree_node;
            tree_node->left = aux_2->tree_node;

            // creation of list_node which is gonna be appended
            struct List_node *aux = (struct List_node *)malloc(sizeof(struct List_node));
            aux->tree_node = tree_node;

            aux->next = expression_tree_stack;
            expression_tree_stack = aux;

        }
        postfix_queue = postfix_queue->next;
    }
    return expression_tree_stack->tree_node;
}

// sorry the code is a shit
struct Queue
{
    struct Queue *next;
    struct Tree_node *node;
};

void enqueue(struct Queue **queue, struct Tree_node *node, int level)
{
    struct Queue *new_node = (struct Queue*)malloc(sizeof(struct Queue));
    if(new_node) {
        new_node->next = NULL;
        new_node->node = node;
        new_node->node->level = level;
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
        exit(1);
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

void bfs(struct Tree_node *tree)
{
    struct Queue *queue = NULL;
    if(tree != NULL) {
        enqueue(&queue, tree, 0);
        int current_level = -1;
        while(queue != NULL) {
            struct Queue *aux = dequeue(&queue);
            int level = aux->node->level;
            if(level != current_level) {
                if(current_level != -1) printf("\n");
                printf("Nivel %d: ", level);
                current_level = level;
            }
            printf("%c", aux->node->value);
            if(aux->node->left != NULL)
                enqueue(&queue, aux->node->left, level+1);
            if(aux->node->right != NULL) {
                enqueue(&queue, aux->node->right, level+1);
            }
            free(aux);
        }
        printf("\n");
    }
}

void dfs_inorder(struct Tree_node *tree)
{
    if(tree == NULL)
        return ;
    dfs_inorder(tree->left);
    printf("%c ", tree->value);
    dfs_inorder(tree->right);
}

void dfs_preorder(struct Tree_node *tree)
{
    if(tree == NULL)
        return ;
    printf("%c ", tree->value);
    dfs_preorder(tree->left);
    dfs_preorder(tree->right);
}

void dfs_postorder(struct Tree_node *tree)
{
    if(tree == NULL)
        return ;
    dfs_postorder(tree->left);
    dfs_postorder(tree->right);
    printf("%c ", tree->value);
}

int main(int argc, char *argv[])
{
    char txt[1000];
    int teste=0;
    while(scanf(" %999[^\n]", txt) != EOF) {
        if(teste++) printf("\n");
        struct List_node *teste = infix_to_postfix(txt);
        struct Tree_node *tree = binary_expression_tree(teste); 
        bfs(tree);
    }

    return 0;
}
