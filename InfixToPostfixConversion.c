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
    if (infix == '+' || infix == '-' || infix == '*' || infix == '/')
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

    if (infix == '*' || infix == '/')
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

char *convertInfixToPostfix(char *infix)
{
    // -------------variable declaration------------
    int i = 0, j = 0;

    // ------------stake values decleration---------
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // -------------coding of infix to postfix-------------
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (!operanderCheck(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else
        {
            if (operanderBigger(infix[i]) > operanderBigger(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[i] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *exp = "L-H-f+dfg/fd*fg";
    printf("%s", convertInfixToPostfix(exp));
    return 0;
}