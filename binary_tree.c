#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// void preOrder(struct node *root)
// {
//     if (root != NULL)
//     {
//         printf("%d\t", root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// int main()
// {
//     struct node *p = createNode(4);
//     struct node *p1 = createNode(1);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(5);
//     struct node *p4 = createNode(2);

//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     preOrder(p);

//     return 0;
// }

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

struct node *search(struct node *root, int key)
{

    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }

    return search(root, key);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 56);
    insert(root, 34);
    insert(root, 23);
    insert(root, 45);
    insert(root, 78);

    if (search(root, 2) != NULL)
    {
        printf("Found");
    }
    else
    {
        printf("Not Found");
    }

    return 0;
}