#include "rabin_karp.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define base 256
#define prime 101

int* find_substr(char* txt, char* pat, int* size)
{
    *size = 0;
    int txt_len = strlen(txt), pat_len = strlen(pat);
    int h=1;
    int hash_txt=0, hash_pat=0;
    register int i, j;

    int capacity=2;
    int* ans = (int*)malloc(capacity*sizeof(int));
    
    for(i=0; i<pat_len-1; i++)
        h = (base*h)%prime;

    for(i=0; i<pat_len; i++)
    {
        hash_txt = (hash_txt*base + txt[i])%prime;
        hash_pat = (hash_pat*base + pat[i])%prime;
    }

    for(i=0; i<=txt_len-pat_len; i++)
    {
        printf("hash_pat: %d\nhash_txt: %d\n\n", hash_pat, hash_txt);
        if(hash_txt == hash_pat)
        {
            for(j=0; j<pat_len; j++)
            {
                if(txt[i+j] != pat[j])
                    break;
            }
            if(j == pat_len)
            {
                if(*size == capacity)
                {
                    capacity *= 2;
                    ans = (int*)realloc(ans, capacity*sizeof(int));
                }
                ans[(*size)++] = i;
            }
        }
        if(i<txt_len-pat_len)
        {
            hash_txt = ((hash_txt - txt[i]*h)*base + txt[i+pat_len])%prime;
            if(hash_txt < 0)
                hash_txt += prime;
        }
    }
    if(*size == 0)
    {
        free(ans);
        return NULL;
    }
    ans = (int*)realloc(ans, (*size)*sizeof(int));

    return ans;
}
