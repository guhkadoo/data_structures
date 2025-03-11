#include "gcd.h"

static inline void swap(int* a, int* b) { int aux = *a; *a = *b; *b = aux; }

int gcd(int a, int b)
{
    if(b>a)
        swap(&a, &b);
    if(a%b == 0)
        return b;
    gcd(b, a%b);
}
