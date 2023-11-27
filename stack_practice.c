#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[100];
int top = -1;

void push(int data)
{
    arr[top] = data;
    top++;
}

void display()
{
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d\t", arr[i]);
    }
}

char pop()
{
    return arr[--top];
}
// int peek()
// {
//     return arr[top];
// }
// int main()
// {

//     int size;
//     printf("Enter the size of the stack: ");
//     scanf("%d", &size);
//     if (top == -1)
//     {
//         top = 0;
//     }

//     arr = (int *)malloc(size * sizeof(int));

//     for (int i = 0; i < size; i++)
//     {
//         int data;
//         printf("Enter the data: ");
//         scanf("%d", &data);
//         push(data);
//     }

//     display();
//     printf("\npop element in stack: %d", pop());
//     printf("\npeek element in stack: %d", peek());
//     return 0;
// }

//* infix to postfix
int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

char *converter(char infix[])
{

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    char x;
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (precedence(infix[i]) > precedence(arr[top]))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
        else
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        printf("postfix expression: %s\n", postfix);
    }
    postfix[j] = '\0';

    return postfix;
}
int main()
{
    char infix[100] = "((a+b)*c)";
    printf("infix expression %s\n", infix);
    printf("postfix expression %s", converter(infix));
    return 0;
}