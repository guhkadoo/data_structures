#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
public:
    void push(int);
    int pop();
    int empty();
    int top();
    int size();
    void print();
    Stack();
    Stack(int);
private:
    int _size;
    struct Node *_top;
};

#endif //STACK_HPP
