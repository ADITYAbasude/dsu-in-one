#include <stdio.h>
#include <stdlib.h>
struct linked
{
    int data;
    struct linked *next;
};

void transversal(struct linked *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct linked *first;
    struct linked *second;
    struct linked *third;
    struct linked *forth;
    struct linked *fivth;
    struct linked *sixth;

    first = (struct linked *)malloc(sizeof(struct linked));
    second = (struct linked *)malloc(sizeof(struct linked));
    third = (struct linked *)malloc(sizeof(struct linked));
    forth = (struct linked *)malloc(sizeof(struct linked));
    fivth = (struct linked *)malloc(sizeof(struct linked));
    sixth = (struct linked *)malloc(sizeof(struct linked));

    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = forth;
    forth->data = 4;
    forth->next = fivth;
    fivth->data = 5;
    fivth->next = sixth;
    sixth->data = 6;
    sixth->next = NULL;

    transversal(first);

    return 0;
}