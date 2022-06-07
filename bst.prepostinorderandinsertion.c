#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {

        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {

        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void Inorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {

        Inorder(ptr->left);
        printf("%d ", ptr->data);
        Inorder(ptr->right);
    }
}

void insert(struct node **root, struct node *prev, int val)
{
    struct node *itr = *root;
    if (*root == NULL && prev == NULL)
    {
        *root = create(val);
        return;
    }
    if (*root == NULL)
    {
        if (prev->data > val)
        {
            prev->left = create(val);
        }
        else
        {
            prev->right = create(val);
        }
    }
    else
    {
        if (itr->data == val)
        {
            printf("No Duplicate Values Allowed\n");
        }
        else if (itr->data > val)
        {
            insert(&itr->left, itr, val);
        }
        else
        {
            insert(&itr->right, itr, val);
        }
    }
}
int main()
{
    int val;
    struct node *p1 = NULL;
    int ch;
    while (1)
    {
        printf("\n");
        printf("\t\t\t\t1.Add value in Tree\n");
        printf("\t\t\t\t2.Pre-order Travrsal\n");
        printf("\t\t\t\t3.In-order Traversal\n");
        printf("\t\t\t\t4.Post-order Traversal\n");
        printf("\t\t\t\t5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the Value: ");
            scanf("%d", &val);
            insert(&p1, NULL, val);
        }
        else if (ch == 2)
        {
            preorder(p1);
        }
        else if (ch == 3)
        {
            Inorder(p1);
        }
        else if (ch == 4)
        {
            postorder(p1);
        }
        else
        {
            break;
        }
    }
    return 0;
}
