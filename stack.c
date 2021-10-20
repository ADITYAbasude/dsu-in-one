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

void bubbleshort(struct stack *ptr)
{
    int temp;
    // printf("%d" , ptr->top);
    printf("\n");
    for (int i = ptr->top; i < ptr->size; i++)
    {
        for (int j = i + 1; j < ptr->size; i++)
        {
            if (ptr->arr[i] > ptr->arr[j])
            {
                temp = ptr->arr[i];
                ptr->arr[i] = ptr->arr[j];
                ptr->arr[j] = temp;
            }
        }
    }
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s);
    display(s);
    // pop(s);
    bubbleshort(s);
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