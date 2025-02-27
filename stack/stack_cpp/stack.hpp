#ifndef STACK_HPP
#define STACK_HPP
#include <cstdio>
#include <stdexcept>

template <class T>
class Stack
{
public:
    void push(T);
    T pop();
    bool empty();
    T top();
    int size();
    void print();
    Stack();
    Stack(T);
private:
    struct Node;
    int _size;
    Node* _top;
};

template <class T> struct Stack<T>::Node
{
    T value;
    Node* next;
};

template <class T> Stack<T>::Stack() : _top(nullptr), _size(0) {}

template <class T> Stack<T>::Stack(T n) : _top(new Node{n, nullptr}), _size(1) {}

template <class T> void Stack<T>::push(T n)
{
    struct Node* new_node = new Node{n, _top};
    _top = new_node;
    _size++;
}

template <class T> T Stack<T>::pop()
{
    if(_top != nullptr)
    {
        struct Node* remove = _top;
        T ret = _top->value;
        _top = _top->next;
        delete remove;
        _size--;
        return ret;
    }
    throw std::out_of_range("stack underflow");
}

template <class T> bool Stack<T>::empty()
{
    return (_size == 0);
}

template <class T> T Stack<T>::top()
{
    if(_top != nullptr)
        return _top->value;
    throw std::out_of_range("stack underflow");
}

template <class T> int Stack<T>::size()
{
    return _size;
}

template <class T> void Stack<T>::print()
{
    struct Node* aux = _top;
    if(aux != nullptr)
    {
        printf("[%d", aux->value);
        aux = aux->next;
        while(aux != nullptr && aux->next != nullptr)
        {
            printf(" -> %d", aux->value);
            aux = aux->next;
        }
        if(aux != nullptr)
            printf(" -> %d]\n", aux->value);
        else
            printf("]\n");
    }
}

#endif //STACK_HPP
