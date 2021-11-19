#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int *arr;
    int f, r;
};

int QisFull(struct Queue *q)
{
    if (q->r == 5)
    {
        printf("Queue is overflow ");
        return 1;
    }
    return 0;
}
int QisEmpty(struct Queue *q)
{
    if (q->f < 6)
    {
        printf("Queue is underflow ");
        return 1;
    }
    return 0;
}
void Inqueue(struct Queue *q)
{
    int num;
    if (q->r < 6)
    {
        for (int i = 0; i < 6; i++)
        {

            q->r++;
            scanf("%d", &num);
            q->arr[q->r] = num;
        }
    }

}

void dequeue(struct Queue *q, int p)
{
    if (q->f != 6)
    {
        int temp;
        for (int i = 0; i < 6; i++)
        {
            q->f++;
            if (q->f == p)
            {

                temp = q->arr[q->f];
                q->arr[q->f] = 0;
            }
        }
    }
}

void display(struct Queue *q)
{
    for (int i = 0; i < 6; i++)
    {

        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = -1;
    q->r = -1;

    q->arr = (int *)malloc(6 * sizeof(int));

    Inqueue(q);
    display(q);
    dequeue(q, 4);
    display(q);
    return 0;
}