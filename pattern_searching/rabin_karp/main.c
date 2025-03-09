#include <stdio.h>
#include "rabin_karp.h"

int main(int argc, char* argv[])
{
    char* strs[2] = {"Testando a minha funcao nova, eh minha mi mi mi minha! im im im im imim", "mi"};
    int size;
    int *n = find_substr(strs[0], strs[1], &size);
    printf("size: %d\n", size);
    for(int i=0; i<size; i++)
        printf("%d ", n[i]);
    printf("\n");

    return 0;
}
