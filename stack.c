#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

void push(struct stack *ptr)
{
    int a;
    while (ptr->top != ptr->size - 1)
    {
        scanf("%d", &a);
        ptr->top++;
        ptr->arr[ptr->top] = a;
    }
}
void display(struct stack *ptr)
{
    while (ptr->top != -1)
    {
        printf("%d\t", ptr->arr[ptr->top]);
        ptr->top--;
    }
}

void pop(struct stack *ptr)
{
    int temp;
    while (ptr->top != -1)
    {
        temp = ptr->arr[ptr->top];
        ptr->top--;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Enter the element in stack\n");
    push(s);
    display(s);
    pop(s);
    display(s);
    if (isEmpty(s))
    {
        printf("\nStack is Underflow");
    }
    else if (isFull(s))
    {
        printf("\nStack is Overflow");
    }

    return 0;
}