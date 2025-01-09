#include <stdio.h>

int fat(int n)
{
    if(n==1 || n==0)
        return 1;
    return n*fat(n-1);
}


int main(int argc, char *argv[])
{
    while(1) {
        int n;
        printf("Digite o numero do fatorial: ");
        scanf("%d", &n);
        printf("\nResultado: %d\n", fat(n));
    }

    return 0;
}
