#include "stack.h"
#include <string.h>

#define MAX 100

/*
int fatorial(int num)
{
    struct Stack *stack = NULL;
    int res=1;

    while(num>1) {
        push(&stack, num--);
    }
    while(stack != NULL) {
        res *= (pop(&stack))->value;
    }
    return res;
}

int correct_pair(char in_stack, char not_in_stack)
{
    if(in_stack == '(' && not_in_stack == ')')
        return 1; 
    else if(in_stack == '[' && not_in_stack == ']')
        return 1;
    else if(in_stack == '{' && not_in_stack == '}')
        return 1;
    return 0;
}

int verify_expression(char expression[])
{
    struct Stack *stack = NULL;
    for(int i=0; expression[i] != '\0'; i++) {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            struct Stack *aux = pop(&stack);
            if(aux == NULL || correct_pair(aux->value, expression[i]) == 0) {
                return 0;
            }
            free(aux);
        }
    }
    if(stack == NULL)
        return 1;
    return 0;
}

void reverse_string(char expression[])
{
    struct Stack *stack = NULL;
    for(int i=0; expression[i] != '\0'; i++) {
        push(&stack, expression[i]);
    }
    while(stack != NULL) {
        struct Stack *aux = pop(&stack);
        printf("%c", aux->value);
        free(aux);
    }
    printf("\n");
}
*/

float solve_reverse_polish(char expression[])
{
    struct Stack *stack = NULL;
    char str_num[MAX] = "", operation;
    int j=0;
    float number;
    //adds ' ' to the final of the expression:
    strcat(expression, " ");

    for(int i=0; expression[i]!='\0'; i++) {
        if((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
            str_num[j++] = expression[i];
        } else if(expression[i] == ' ') {
            if(strcmp(str_num, "")) {
                number = atof(str_num); 
                push(&stack, number);
                memset(str_num, 0, sizeof(char)*MAX); j=0; //sets str_num="" and j=0;                                           
            } else {
                struct Stack *num_1 = pop(&stack);
                struct Stack *num_2 = pop(&stack);
                if(operation == '+')
                    push(&stack, num_2->value + num_1->value);
                else if(operation == '-')
                    push(&stack, num_2->value - num_1->value);
                else if(operation == '*')
                    push(&stack, num_2->value * num_1->value);
                else if(operation == '/')
                    push(&stack, num_2->value / num_1->value);
                free(num_1);
                free(num_2);
            }
        } else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operation = expression[i];
        }
    }
    struct Stack *answer_node = pop(&stack);
    float answer = answer_node->value; 
    free(answer_node);
    return answer; 
}


int main(int argc, char *argv[])
{
    char expression[50];
    while(1) {
        printf("Write down a reverse polish notation expression: ");
        scanf(" %49[^\n]", expression);
        float ans = solve_reverse_polish(expression);
        printf("The answer is %.3f\n", ans);
        /*
        printf("Write down a sentence to be reversed: ");
        scanf(" %49[^\n]", expression);
        reverse_string(expression);
        */


        /*
        printf("Write down an arithmetic expression: ");
        scanf(" %49[^\n]", expression);
        if(verify_expression(expression) == 1) {
            printf("You inserted a RIGHT arithmetic expression!\n");
        } else {
            printf("You inserted a WRONG arithmetic expression!\n");
        }
        */
    }


    return 0;
}
