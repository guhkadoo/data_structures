#include "shunting_yard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

// ------------------------------- STACK ------------------------------------
struct _node
{
    char value;
    struct _node* next;
};

struct _stack
{
    struct _node* top;
    int size;
};

void stack_initialize(stack* s)
{
    (*s) = (stack)malloc(sizeof(struct _stack));
    if((*s))
    {
        (*s)->top = NULL;
        (*s)->size = 0;
    } else {
        EXIT_WITH_ERROR("error while allocating stack");
    }
}

struct _node* create_node(char c)
{
    struct _node* new_node = (struct _node*)malloc(sizeof(struct _node));
    if(new_node)
    {
        new_node->value = c;
        new_node->next = NULL;
    } else {
        EXIT_WITH_ERROR("error while allocating new node");
    }
    return new_node;
}

void stack_push(stack s, char c)
{
    struct _node* new_node = create_node(c);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}

char stack_pop(stack s)
{
    if(s->top == NULL)
        EXIT_WITH_ERROR("stack underflow");
    struct _node* tb_removed = s->top;
    char c = tb_removed->value;

    s->top = tb_removed->next;
    free(tb_removed);
    s->size--;
    return c; 
}

char stack_is_empty(stack s)
{
    return (s->size == 0);
}

void stack_print(stack s)
{
    if(s->top != NULL)
    {
        struct _node* aux = s->top->next;
        printf("[%c", s->top->value);
        while(aux != NULL)
        {
            printf(" -> %c", aux->value);
            aux = aux->next;
        }
        printf("]\n");
    } else {
        printf("[]\n");
    }
}

char stack_top(stack s)
{
    return s->top->value;
}

int stack_size(stack s)
{
    return s->size;
}
// --------------------------------------------------------------------------





// --------------------------- SHUNTING YARD --------------------------------

char is_letter(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    return 0;
}

char is_operator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    return 0;
}

int precedence(char c)
{
    if(c=='^') return 2;
    else if(c=='*' || c=='/') return 1;
    return 0;
}

char has_higher_precedence(char c, char stack_value)
{
    if(stack_value == '(')
        return 1;

    if(precedence(c) > precedence(stack_value))    
        return 1;
    return 0;
}

char* shunting_yard(char* infix)
{
    int infix_len = strlen(infix);
    char* postfix = (char*)malloc(infix_len);
    if(postfix != NULL)
    {
        stack s;
        stack_initialize(&s);
        register int i=0, j=0;
        int f_idx;
        char c;
        while(i<infix_len)
        {
            c = infix[i];
            if(is_letter(c))
                postfix[j++] = c;
            else if(is_operator(c))
            {
                if(stack_is_empty(s) || has_higher_precedence(c, s->top->value))
                    stack_push(s, c);
                else
                {
                    while(!stack_is_empty(s) && !has_higher_precedence(c, s->top->value))
                        postfix[j++] = stack_pop(s);
                    stack_push(s, c);
                }
            }
            else if(c == '(')
                stack_push(s, c);
            else if(c == ')')
            {
                while(stack_top(s) != '(')
                    postfix[j++] = stack_pop(s);
                stack_pop(s);
            }
            i++;
        }
        while(!stack_is_empty(s))
            postfix[j++] = stack_pop(s);
        postfix[j] = '\0';
    } else {
        EXIT_WITH_ERROR("error while allocating char* postfix");
    }
    return postfix;
}
// --------------------------------------------------------------------------
