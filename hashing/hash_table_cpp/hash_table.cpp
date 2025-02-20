#include "hash_table.hpp"
#include <cstddef>

#define GOLDEN_RATIO 0x9e3779b1
#define INT_BIT 8*sizeof(int)

int Hash_table::hash_function(int key)
{
    return (key * GOLDEN_RATIO) >> (INT_BIT-bit_size); 
}

Hash_table::Hash_table(int b_size)
{
    bit_size = b_size;
    ht_size = 0;
    lists = new List[(1<<bit_size)];
}

void Hash_table::add(int key, std::string value_name)
{
    int idx = hash_function(key);
    lists[idx].push_back(key, value_name);
}

std::string Hash_table::get(int key)
{
    int idx = hash_function(key);
    return lists[idx].get(key);  
}

void Hash_table::remove(int key)
{
    int idx = hash_function(key);
    lists[idx].remove(key);
}

void Hash_table::print()
{
    for(int i=0; i<(1<<bit_size); i++)
        lists[i].print();
}

void Hash_table::deallocate()
{
    for(int i=0; i<(1<<bit_size); i++)
        lists[i].deallocate();
}
