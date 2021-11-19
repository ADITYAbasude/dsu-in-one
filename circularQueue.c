#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f, r;
    int *arr;
};

int full(struct queue *q)
{
    if ((q->r == 4 && q->f == 0) || (q->f = q->r + 1))
    {

        return 1;
    }
    return 0;
}

int empty(struct queue *q)
{
    if (q->f < 5)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q)
{
    int num, r;

    if (q->f == -1)
    {
        q->r = 0;
        q->f = 0;
    }
    r = q->r;
    if (!full(q))
    {

        printf("Queue is OverFlow! ");
    }

    else
    {
        while (r < 5)
        {
            scanf("%d", &num);
            q->arr[r] = num;
            r++;
        }
    }
}

void dequeue(struct queue *q, int p)
{
    if (q->f == -1)
    {
        q->r = 0;
        q->f = 0;
    }
    if (empty(q))
    {
        while (q->f < 5)
        {
            if (q->f == p)
            {
                q->arr[q->f] = NULL;
            }
            q->f++;
        }
    }
    q->f = 0;
}

void display(struct queue *q)
{

    while (q->r < 5)
    {
        printf("%d\t", q->arr[q->r]);
        q->r++;
    }
    q->r = 0;
    printf("\n");
}

void insertion(struct queue *q ,int val ,int p){
    while (q->r <= p)
    {
        if (q->r == p)
        {
            q->arr[q->r] = val;
        }
        q->r++;
        
    }
    q->r = 0;
    
}


int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(5 * sizeof(int));

    enqueue(q);
    display(q);
    dequeue(q, 2);
    display(q);
    insertion(q , 6 , 2);
    display(q);
    return 0;
}