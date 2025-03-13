#include <stdio.h>
#include <stdlib.h>

static int i = 0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int count;
};

void inorder_traversal(struct node *head, int arr[])
{
    if (head != NULL)
    {
        inorder_traversal(head->left, arr);
        int c = head->count;
        while (c > 0)
        {
            arr[i] = head->data;
            i++;
            c--;
        }
        inorder_traversal(head->right, arr);
    }
}

struct node *bst_insert(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->count = 1;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        int key = 0;
        struct node *old_ptr = head;
        struct node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                ptr->count = ptr->count + 1;
                // printf("%d ", ptr->count);
                key = 1;
                break;
            }
            else if (ptr->data > x)
            {
                old_ptr = ptr;
                ptr = ptr->left;
            }
            else if (ptr->data < x)
            {
                old_ptr = ptr;
                ptr = ptr->right;
            }
        }
        if (key == 0)
        {
            if (old_ptr->data > x)
            {
                old_ptr->left = temp;
            }
            else if (old_ptr->data < x)
            {
                old_ptr->right = temp;
            }
        }
    }
    return head;
}

void bst_sort(int arr[], int n)
{
    struct node *head = malloc(sizeof(struct node));
    head = NULL;
    for (int k = 0; k < n; k++)
    {
        head = bst_insert(head, arr[k]);
    }
    inorder_traversal(head, arr);
}

int main()
{
    int arr[10] = {1, 2, 5, 3, -3, 5, 7, 8, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    bst_sort(arr, size);
    for (int j = 0; j < size; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}