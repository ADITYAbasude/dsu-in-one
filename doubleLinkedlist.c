#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}

struct node *insertionAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    return ptr;
}

struct node *insertionAtBetween(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next->prev = ptr;
    return head;
}

struct node *deletionAtFirst(struct node *head)
{
    struct node *ptr = head;
    ptr = ptr->next;
    ptr->prev = NULL;
    free(head);
    return ptr;
}

struct node *deletionAtBetween(struct node *head, int index)
{
    struct node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
    return head;
}

void findElementInDoubleLinkedList(struct node *head, int data)
{
    struct node *ptr = head;
    int i = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;

        if (ptr->data == data)
        {
            printf("\nElement found at index %d", i);
            break;
        }
    }
    if (ptr->data != data)
    {
        printf("\nElement not found");
    }
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 30;
    head->next = NULL;
    head->prev = NULL;

    head = insertionAtFirst(head, 20);
    head = insertionAtFirst(head, 10);
    head = insertionAtBetween(head, 40, 2);
    // head = deletionAtFirst(head);
    head = deletionAtBetween(head, 2);
    traversal(head);
    findElementInDoubleLinkedList(head, 30);
    return 0;
}