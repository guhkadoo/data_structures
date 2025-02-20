#ifndef LIST_HPP
#define LIST_HPP

#include <string>

class List
{
public:
    List(int, std::string);
    List();
    void push_back(int, std::string);
    void remove(int);
    std::string get(int);
    void print();
    int size();
    void deallocate();
private:
    struct Node *front;
    int l_size;
};

#endif //LIST_HPP
