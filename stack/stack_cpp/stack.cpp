#include "stack.hpp"
#include <cstdio>
#include <cstdlib>
#include <climits>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Node
{
    int value;
    struct Node *next;
};

struct Node *_create_node(int n)
{
    struct Node *new_node = new struct Node;
    if(new_node)
    {
        new_node->value = n;
        new_node->next = NULL;
    } else {
        EXIT_WITH_ERROR("Error while allocating a new node");
    }
    return new_node;
}

Stack::Stack()
{
    _size = 0;
    _top = NULL;
}

Stack::Stack(int n)
{
    _size = 1;
    _top = _create_node(n);
}

void Stack::push(int n)
{
    if(_top == NULL)
        _top = _create_node(n);
    else
    {
        struct Node *new_node = _create_node(n);
        new_node->next = _top;
        _top = new_node;
    }
    _size++;
}

int Stack::pop()
{
    if(_top != NULL)
    {
        struct Node *remove = _top;
        int ret = _top->value;
        _top = _top->next;
        delete remove;
        _size--;
        return ret;
    }
    return INT_MIN; 
}

int Stack::empty()
{
    if(_size == 0)
        return 1;
    return 0;
}

int Stack::top()
{
    return _top->value;
}

int Stack::size()
{
    return _size;
}

void Stack::print()
{
    struct Node *aux = _top;
    if(aux != NULL)
    {
        printf("[%d", aux->value);
        aux = aux->next;
        while(aux != NULL && aux->next != NULL)
        {
            printf(" -> %d", aux->value);
            aux = aux->next;
        }
        if(aux != NULL)
            printf(" -> %d]\n", aux->value);
        else
            printf("]\n");
    }
}
