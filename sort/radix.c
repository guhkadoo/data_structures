#include <stdio.h>
#define ARRAY_SIZE(v) sizeof(v)/sizeof(v[0])

int getmax(int v[], int len)
{
    int max = v[0];
    for(int i=1; i<len; i++) 
        if(v[i]>max) max = v[i];
    return max;
}

void counting_sort(int v[], int len, int exp)
{
    int answer[len];
    int count[10] = {0};

    register int i;
    for(i=0; i<len; i++)
        count[(v[i]/exp)%10]++;
    for(i=1; i<10; i++)
        count[i] += count[i-1];
    for(i=len-1; i>=0; i--) {
        answer[count[(v[i]/exp)%10]-1] = v[i];
        count[(v[i]/exp)%10]--;
    }
    for(i=0; i<len; i++)
        v[i] = answer[i];
}

void radix_sort(int v[], int len)
{
    int max = getmax(v, len);
    
    for(int i=1; max/i>0; i*=10)
        counting_sort(v, len, i);
}


int main(int argc, char *argv[])
{
    int v[] = {1761,23,6,31,1,2,0,3263773,2,3};
    radix_sort(v, ARRAY_SIZE(v));
    for(register int i=0; i<ARRAY_SIZE(v); i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
