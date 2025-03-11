#include "gcd.h"

static inline void swap(int* a, int* b) { int aux = *a; *a = *b; *b = aux; }

int gcd(int a, int b)
{
    if(b>a)
        swap(&a, &b);
    return b == 0 ? a : gcd(b, a%b);
}
