#include "list.hpp"
#include <cstddef>
#include <cstdio>
#include <string>

struct Node 
{
    int key;
    std::string value_name;
    struct Node *next;
};

List::List() : l_size(0), front(nullptr) {};

List::List(int key, std::string value_name) : front(new Node{key, value_name, NULL}), l_size(1) {};

void List::push_back(int key, std::string value_name)
{
    struct Node *new_node = new Node{key, value_name, NULL};
    struct Node *aux = front; 
    while(aux != NULL && aux->next != NULL)
    {
        aux = aux->next;
    }
    if(aux != NULL)
        aux->next = new_node;
    else
        front = new_node;
    l_size++;
}

void List::remove(int key)
{
    struct Node *aux = front;
    struct Node *remove = NULL;
    if(aux != NULL) 
    {
        if(aux->key == key)
        {
            remove = front;
            front = front->next;
            l_size--;
        }
        else {
            while(aux->next != NULL && aux->next->key != key)
            {
                aux = aux->next;
            }
            if(aux->next != NULL)
            {
                remove = aux->next;
                aux->next = remove->next;
                l_size--;
            }
        }
        delete remove;
    }
}

std::string List::get(int key)
{
    struct Node *aux = front;
    while(aux != NULL && aux->key != key)
        aux = aux->next;
    if(aux != NULL)
        return aux->value_name;
    return std::string();
}

void List::print()
{
    if(front != NULL)
    {
        printf("[%d  %s", front->key, front->value_name.c_str());
        struct Node *aux = front->next;
        while(aux != NULL && aux->next != NULL)
        {
            printf(" -> %d %s", aux->key, aux->value_name.c_str());
            aux = aux->next;
        }
        if(aux != NULL)
        {
            printf(" -> %d %s]\n", aux->key, aux->value_name.c_str());
        } else {
            printf("]\n");
        }
    } else {
        printf("empty list\n"); 
    }
}

int List::size()
{
    return l_size;
}

void List::deallocate()
{
    struct Node *aux;
    while(front != NULL)
    {
        aux = front->next;
        remove(front->key);
        front = aux; 
    }
}
