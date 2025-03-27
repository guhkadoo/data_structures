#include "prefix_to_postfix.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void substr(char* source, size_t idx, size_t size, char* destination)
{
    size_t i;
    for(i=0; size!=0; size--, i++, idx++)
        destination[i] = source[idx];
    destination[i] = '\0';
}

size_t find(char* prefix)
{
    char temp[MAX_LENGTH];
    size_t len;
    if((len = strlen(prefix)) == 0)
        return 0;
    else if(isalpha(prefix[0]))
        return 1;
    else if(len < 2)
        return 0;
    substr(prefix, 1, len-1, temp);
    size_t m = find(temp);
    if(m == 0 || m == len-1) // no valid prefix operand or no second operand
        return 0;
    substr(prefix, m+1, len-m-1, temp);
    size_t n = find(temp);
    if(n == 0)
        return 0;
    return m+n+1;
}

static int is_operand(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void convert(char* prefix, char* postfix)
{
    char opnd1[MAX_LENGTH], opnd2[MAX_LENGTH];
    char post1[MAX_LENGTH], post2[MAX_LENGTH];
    char temp[MAX_LENGTH];
    char op[2];
    size_t length;
    size_t i, j, m, n;

    if((length = strlen(prefix)) == 1)
    {
        if(isalpha(prefix[0]))
        {
            postfix[0] = prefix[0];
            postfix[1] = '\0';
            return;
        }
        EXIT_WITH_ERROR("1 illegal prefix string");
    }
    op[0] = prefix[0];
    op[1] = '\0';
    substr(prefix, 1, length-1, temp);
    m = find(temp);
    substr(prefix, m+1, length-m-1, temp);
    n = find(temp);
    if(!is_operand(op[0]) || m == 0 || n == 0 || (m+n+1) != length)
        EXIT_WITH_ERROR("2 illegal prefix string");
    substr(prefix, 1, m, opnd1);
    substr(prefix, m+1, n, opnd2);
    convert(opnd1, post1);
    convert(opnd2, post2);
    strcat(post1, post2);
    strcat(post1, op);
    strcpy(postfix, post1);
}
