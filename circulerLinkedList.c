#include <stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *next;
};

void display(struct list *head){
    while (head->next != head)
    {
        printf("%d\t" , head->data);
        head = head->next;
    }
    printf("%d" , head->data);
    printf("\n");
    
}

struct list * insertAtFirst(struct list *head , int val){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->data = val;
    node->next = head;
    return node; 
}

struct list * insertAtBetween(struct list * head , int data , int index){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    struct list *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    node->data = data;
    node->next = p->next;
    p->next = node;
    return head;
    
}

struct list * insertionAtEnd(struct list *head , int data){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    struct list *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    node->data = data;
    p->next = node;
    node->next = head;
    return head;
}


int main()
{
    struct list *head = (struct list *)malloc(sizeof(struct list));
    head->data = 2;
    head->next = head;
    display(head);
    head = insertAtFirst(head , 5);
    head = insertAtBetween(head , 15 , 1);
    // head = insertionAtEnd(head , 20);
    display(head);
    return 0;
}