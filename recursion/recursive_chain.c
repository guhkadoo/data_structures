#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXSTRINGSIZE 101 // INCLUDES '\0' 

void readstr(char*, int*);
int getsymb(char*, int, int*);
int expr(char*, int, int*);
int term(char*, int, int*);
int factor(char*, int, int*);

int main(int argc, char* argv[])
{
    char str[MAXSTRINGSIZE];
    int size, pos=0;

    readstr(str, &size);
    if(expr(str, size, &pos) == TRUE && pos >= size)
        printf("%s valid\n");
    else
        printf("%s invalid\n"); 

    /*
        The condition can fail for one (or both) of two
        reasons. If expr(str, length, &pos) == FALSE
        then there is no valid expression beginning at pos
        If pos < length there may be a valid expression
        starting at pos but it does not occupy the entire string.
    */

    return 0;
}

void readstr(char* str, int* length)
{
    (*length) = 0;
    for(char c; (c=getc(stdin)) != '\n' && (*length)<MAXSTRINGSIZE-1; (*length)++)
        str[(*length)] = c;
    str[(*length)] = '\0';
}

int getsymb(char* str, int length, int* ppos)
{
    return ((*ppos) < length) ? str[(*ppos)++] : ((*ppos)++, '\0'); 
}

int expr(char* str, int length, int* ppos)
{
    if(term(str, length, ppos) == FALSE)
        return FALSE;
    if(getsymb(str, length, ppos) != '+')
    {
        (*ppos)--;
        return TRUE;
    }
    return term(str, length, ppos);
}

int term(char* str, int length, int* ppos)
{
    if(factor(str, length, ppos) == FALSE)
        return FALSE;
    if(getsymb(str, length, ppos) != '*')
    {
        (*ppos)--;
        return TRUE;
    }
    return factor(str, length, ppos);
}

int factor(char* str, int length, int* ppos)
{
    char c;
    if((c = getsymb(str, length, ppos)) !=  '(')
        return isalpha(c);
    return expr(str, length, ppos) && getsymb(str, length, ppos) == ')';
}
