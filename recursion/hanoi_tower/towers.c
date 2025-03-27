#include "towers.h"
#include <stdio.h>

void towers(int n, char frompeg, char topeg, char auxpeg)
{
    if(n==1)
    {
        printf("move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }
    towers(n-1, frompeg, auxpeg, topeg);
    printf("move disk %d from peg %c to peg %c\n", n, frompeg, topeg);
    towers(n-1, auxpeg, topeg, frompeg);
}
