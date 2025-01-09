#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// BEECROWD EXERCISE 1463

struct Tree_node
{
    char[] valuec;
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
    struct List_node *aux = *list;

    // checks if the list is empty, if it is then return remove (NULL)
    if(aux != NULL) {
        if(aux->next == NULL) { // checks if the list has only one element
            remove = aux;
            *list = NULL;
        } else { // if the list has two or more elements, we can check aux->next->next
            while(aux->next->next != NULL) {
                aux = aux->next;
            }
            remove = aux->next;
            aux->next = NULL;
        }
    }

    return remove;
}

struct List_node *top(struct List_node *list)
{
    if(list != NULL) {
        while(list->next == NULL) {
            list = list->next;
        }
        return list;
    }
    return NULL;
}

int has_higher_precedence(char operator_1, char operator_2)
{
    if(operator_1 == '*' || operator_1 == '/') {
        if(operator_2 == '+' || operator_2 == '-') return 1;
    }
    return 0;
}

int is_operand(char *str)
{
    for(int i=0; *(str+i)!='\0'; i++) {
        if(*(str+i) < '0' || *(str+i) > '9')
            return 0;
    }
    return 1;
}

int is_operator(char *str)
{
    if(!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/"))
        return 1;
    return 0;
}

struct List_node *infix_to_postfix(char infix_expression[])
{
    struct List_node *operator_stack = NULL;
    struct List_node *postfix_queue = NULL;
    
    char *token = strtok(infix_expression, " ");
    while(token != NULL) {
        if(is_operand(token)){ 
            append(&postfix_queue, token);
        } else if(is_operator(infix_expression[i])){
            if(operator_stack == NULL || top(operator_stack)->tree_node->value == '(' || has_higher_precedence(infix_expression[i], top(operator_stack)->tree_node->value)) append(&operator_stack, infix_expression[i]);
            else {
                while(operator_stack != NULL && has_higher_precedence(top(operator_stack)->tree_node->value, infix_expression[i])) {
                    struct List_node *aux = pop(&operator_stack);
                    append(&postfix_queue, aux->tree_node->value);
                    printf("appending operator: %c\n", aux->tree_node->value);
                    free(aux);
                }
                append(&operator_stack, infix_expression[i]);
            }
        } else if(infix_expression[i] == '(') {
            append(&operator_stack, infix_expression[i]);
        } else if(infix_expression[i] == ')') {
            while(top(operator_stack)->tree_node->value != ')') {
                struct List_node *aux = pop(&operator_stack);
                append(&postfix_queue, aux->tree_node->value);
                free(aux);
            }
        }
        token = strtok(NULL, " ");
    }
    while(operator_stack != NULL) {
        struct List_node *aux = pop(&operator_stack);
        append(&postfix_queue, aux->tree_node->value);
        free(aux);
    }
    return postfix_queue;
}

void print_stack(struct List_node *stack)
{
    while(stack != NULL) {
        printf("%c, ", stack->tree_node->value);
        stack = stack->next;
    }
}



int main(int argc, char *argv[])
{
    char txt[50];
    scanf(" %49[^\n]", txt);
    struct List_node *teste = infix_to_postfix(txt);
    print_stack(teste);

    return 0;
}
