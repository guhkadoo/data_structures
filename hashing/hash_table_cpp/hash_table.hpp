#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include "list.hpp"

class Hash_table
{
public:
    Hash_table(int);
    void add(int, std::string); 
    std::string get(int);
    void remove(int);
    void print();
    void deallocate();
private:
    int ht_size;
    int bit_size;
    List *lists;
    int hash_function(int);
};

#endif //HASH_TABLE_HPP
