#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
int operanderCheck(char infix)
{
    if (infix == '+' || infix == '-' || infix == '*' || infix == '/' || infix == '$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int operanderBigger(char infix)
{
    if (infix == '$')
        return 4;
    else if (infix == '*' || infix == '/')
        return 3;
    else if (infix == '-' || infix == '+')
        return 2;
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void convertInfixToPostfix(char *infix, int size1)
{
    char *result;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size1;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int i =0 , j= 0;

    while (infix[i] != '\0')
    {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){

            result[j] = c;
            j++;
        }
       
    }

    while (!isEmpty(s))
    {
        result[j] = s->top;
        pop(s);
        j++;
    }

    printf("%s", result);
}

int main()
{
    char *exp = "a+b*c-(d/e+f*g*h)";
    int size = sizeof(exp) / sizeof(exp[0]);
    convertInfixToPostfix(exp, size);            
    return 0;
}