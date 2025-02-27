#include <iostream>
#include "stack.hpp"

int main(int argc, char *argv[])
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Size: " << s.size() << '\n';
    s.print();
    int n1 = s.pop();
    int n2 = s.pop();
    int n3 = s.pop();
    int n4 = s.pop();
    std::cout << "Size: " << s.size() << '\n';
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << '\n';
    s.print();

    return 0;
}
