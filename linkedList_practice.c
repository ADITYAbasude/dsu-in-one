#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};

struct list *insertAtFirst(struct list *head, int data)
{
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->data = data;
    node->next = head;
    return node;
}

struct list *insertAtBetween(struct list *head, int data, int index)
{
    // create a new node
    struct list *node = (struct list *)malloc(sizeof(struct list));
    // take copy of head
    struct list *p = head;
    // traverse to the index - 1 node
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    node->data = data;
    node->next = p->next;
    p->next = node;
    return head;
}

struct list *insertionAtEnd(struct list *head, int data)
{
    // create a new node
    struct list *node = (struct list *)malloc(sizeof(struct list));
    // take copy of head
    struct list *p = head;
    // traverse to the last node
    while (p->next != NULL)
    {
        p = p->next;
    }
    node->data = data;
    p->next = node;
    node->next = NULL;
    return head;
}

struct list *deletionAtFirst(struct list *head)
{
    struct list *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct list *deletionAtBetween(struct list *head, int index)
{
    struct list *ptr = head;
    struct list *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

struct list *deletionAtEnd(struct list *head)
{
    struct list *ptr = head;
    struct list *q = head->next;
    int i = 0;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

void display(struct list *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{

    struct list *head;

    head = (struct list *)malloc(sizeof(struct list));
    head->data = 10;
    head->next = NULL;
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 6);

    // display(head);
    head = insertAtBetween(head, 11, 2);
    display(head);
    // head = insertionAtEnd(head, 100);
    // display(head);

    // head = deletionAtFirst(head);
    // display(head);

    // head = deletionAtBetween(head , 2);
    // display(head);
    head = deletionAtEnd(head);
    display(head);
    return 0;
}