#include "list.hpp"
#include "hash_table.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Hash_table ht(3);
    ht.add(123, "Gustavo");
    ht.add(124, "Jose Renato");
    ht.add(125, "Samuel");
    ht.add(126, "Eduardo");
    ht.add(127, "Bianca");
    ht.print();
    //std::cout << ht.get(124) << '\n';
    return 0;
}
