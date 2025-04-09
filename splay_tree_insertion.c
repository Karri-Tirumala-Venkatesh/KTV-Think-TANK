#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int key;
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

struct node *bst_insert(int k, struct node *head)
{
    if (head == NULL)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->key = k;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (k > head->key)
    {
        head->right = bst_insert(k, head->right);
    }
    else if (k < head->key)
    {
        head->left = bst_insert(k, head->left);
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

struct node *insert(int k, struct node *head)
{
    head = bst_insert(k, head);
    return head;
}

void preorder(struct node *head)
{
    if (head != NULL)
    {
        printf("%d\n", head->key);
        preorder(head->left);
        preorder(head->right);
    }
}

int main()
{
    struct node *head = NULL;
    int i;
    int n = 100000; // number of nodes
    srand(time(0)); // seed random

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (i = 0; i < n; i++)
    {
        int key = rand();
        head = insert(key, head);
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to insert %d nodes: %f seconds\n", n, cpu_time_used);
    return 0;
}