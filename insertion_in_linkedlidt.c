#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *next;
};

void display(struct link *ptr)
{

    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

struct link *insertionAtbeinning(struct link *head , int data){
    struct link *ptr = (struct link *)malloc(sizeof(struct link));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct link *insertionAtbetween(struct link *head, int data , int index){
    struct link *ptr = (struct link *)malloc(sizeof(struct link));
    struct link *p = head;

    for (int i = 0; i!= index-1; i++)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}



int main()
{
    int data = 40 , index = 1;
    struct link *f;
    struct link *s;
    struct link *t;
    struct link *fo;
    struct link *fiv;

    f = (struct link *)malloc(sizeof(struct link));
    s = (struct link *)malloc(sizeof(struct link));
    t = (struct link *)malloc(sizeof(struct link));
    fo = (struct link *)malloc(sizeof(struct link));
    fiv = (struct link *)malloc(sizeof(struct link));

    // first element
    f->data = 5;
    f->next = s;

    // second element
    s->data = 8;
    s->next = t;

    // third element
    t->data = 4;
    t->next = fo;

    // forth element
    fo->data = 3;
    fo->next = fiv;

    // fivth element
    fiv->data = 10;
    fiv->next = NULL;

    display(f);
    // f = insertionAtbeinning(f , data);
    f = insertionAtbetween( f  , data , index);
    printf("\nAfter insertion  \n");
    
    display(f);

    return 0;
}