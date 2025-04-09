#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    int value;
    struct node *left;
    struct node *right;
};

struct node *splay_right(struct node *head)
{
    struct node *ptr1 = head->left;
    head->left = ptr1->right;
    ptr1->right = head;
    return ptr1;
}

struct node *splay_left(struct node *head)
{
    struct node *ptr2 = head->right;
    head->right = ptr2->left;
    ptr2->left = head;
    return ptr2;
}

struct node *bst_insert(int k, int v, struct node *head)
{
    if (head == NULL)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->key = k;
        temp->value = v;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (k > head->key)
    {
        head->right = bst_insert(k, v, head->right);
    }
    else if (k < head->key)
    {
        head->left = bst_insert(k, v, head->left);
    }
    if (head->key != k)
    {
        if (head->right != NULL && head->right->key == k)
        {
            head = splay_left(head);
        }
        if (head->left != NULL && head->left->key == k)
        {
            head = splay_right(head);
        }
    }
    return head;
}

struct node *insert(int k, int v, struct node *head)
{
    head = bst_insert(k, v, head);
    return head;
}

void preorder(struct node *head)
{
    if (head != NULL)
    {
        printf("%d %d\n", head->key, head->value);
        preorder(head->left);
        preorder(head->right);
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head = NULL;
    head = insert(10, 640, head);
    head = insert(5, 100, head);
    head = insert(3, 150, head);
    head = insert(4, 125, head);
    head = insert(7, 700, head);
    head = insert(11, 500, head);
    head = insert(9, 230, head);
    head = insert(2, 560, head);
    head = insert(6, 580, head);
    head = insert(8, 780, head);
    preorder(head);
}
