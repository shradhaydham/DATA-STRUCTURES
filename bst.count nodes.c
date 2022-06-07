#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

struct node* insert (struct node *ptr, int val)
{
    if (ptr == NULL)
    {
         struct node *new_node = (struct node*)malloc(sizeof(struct node));
         new_node->info = val;
         new_node->left = new_node->right = NULL;
         return new_node;
    }
    else
    {
        if (val == ptr->info)
        {
            printf("Duplicate Values not Allowed.\n");
            return ptr;
        }
        if (val < ptr->info)
        {
            ptr->left = insert (ptr->left, val);
        }
        else
        {
            ptr->right = insert (ptr->right, val);
        }
    }
}
void countnode (struct node *ptr,int *count)
{

    if (ptr == NULL)
    {
        return;
    }
    else
    {
        (*count)++;
        countnode (ptr->left,count);
        countnode (ptr->right,count);
    }
}
void countleafnode (struct node *ptr,int *countleaf)
{

    if (ptr == NULL)
    {
        return;
    }
    else
    {
        if(ptr->left==NULL && ptr->right==NULL)
          {
        (*countleaf)++;
        countleafnode (ptr->left,countleaf);
        countleafnode (ptr->right,countleaf);
          }
          else
            return;
    }
}



void preorder (struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        printf ("%d ", ptr->info);
        preorder (ptr->left);
        preorder (ptr->right);
    }
}

void inorder (struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        inorder (ptr->left);
        printf ("%d ", ptr->info);
        inorder (ptr->right);
    }
}

void postorder (struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        postorder (ptr->left);
        postorder (ptr->right);
        printf ("%d ", ptr->info);
    }
}

void main()
{
    int count=0;
    int countleaf=0;
    int choice, value;
    struct node *root = NULL;
    while (choice != 7)
    {
        printf ("\t1. Insert Element into Tree");
        printf ("\n\t2. Pre-order Traversal");
        printf ("\n\t3. In-order Traversal");
        printf ("\n\t4. Post-order Traversal");
        printf ("\n\t5. count all nodes of tree");
        printf ("\n\t6. count leaf nodes of tree");
        printf ("\n\t7. Exit");
        printf ("\nYour Choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1: printf ("Enter Value to be Inserted: ");
                    scanf ("%d", &value);
                    root = insert (root, value);
                    break;
            case 2: preorder (root);
                    printf("\n");
                    break;
            case 3: inorder (root);
                    printf("\n");
                    break;
            case 4: postorder (root);
                    printf("\n");
                    break;
            case 5: countnode (root,&count);
                    printf("\ntotal no of nodes:%d",count);
                    break;
            case 6: countleafnode (root,&countleaf);
                    printf("\ntotal no of leaf nodes:%d",countleaf);
                    break;
            case 7: exit(0);
            default:
                    printf("Wrong Input. Try Again!");
                    break;
        }
    }
}

