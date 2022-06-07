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

int countAllNode(struct node *root)
{
    if (root != NULL)
    {
        return 1 + countAllNode(root->left) + countAllNode(root->right);
    }
}

int countLeafNode(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL && root->left == NULL)
    {
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void Inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        Inorder(ptr->left);
        printf("%d ", ptr->data);
        Inorder(ptr->right);
    }
}

void insert_doublePtr(struct node **root, int val)
{
    if (*root == NULL)
    {
        *root = create(val);
    }
    else
    {
        if ((*root)->data == val)
        {
            printf("No Duplicate Values Allowed\n");
        }
        else if ((*root)->data > val)
        {
            insert_doublePtr(&(*root)->left, val);
        }
        else
        {
            insert_doublePtr(&(*root)->right, val);
        }
    }
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

void del_doublePtr(struct node **root, int val)
{
    if (*root == NULL)
    {
        printf("Node does not exist\n");
        return;
    }
    else if ((*root)->data > val)
    {
        del_doublePtr(&(*root)->left, val);
    }
    else if ((*root)->data < val)
    {
        del_doublePtr(&(*root)->right, val);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            (*root) = (*root)->right;
            return;
        }
        else if ((*root)->right == NULL)
        {
            (*root) = (*root)->left;
            return;
        }
        struct node *temp = inOrderPredecessor(*root);
        (*root)->data = temp->data;
        del_doublePtr(&(*root)->left, temp->data);
    }
}

int main()
{
    int val, delval;
    int n;
    struct node *p1 = NULL;
    struct node *pre = NULL;
    int ch;
    while (1)
    {
        printf("\n");
        printf("\t\t\t\t1.Add value in Tree\n");
        printf("\t\t\t\t2.Pre-order Travrsal\n");
        printf("\t\t\t\t3.In-order Traversal\n");
        printf("\t\t\t\t4.Post-order Traversal\n");
        printf("\t\t\t\t5.Count Nodes\n");
        printf("\t\t\t\t6.Count Leaf Nodes\n");
        printf("\t\t\t\t7.Delete Node\n");
        printf("\t\t\t\t8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the Value: ");
            scanf("%d", &val);
            insert_doublePtr(&p1,val);
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
        else if (ch == 5)
        {
            n = countAllNode(p1);
            printf("Toatal Nodes in BST: %d\n", n);
        }
        else if (ch == 6)
        {
            n = countLeafNode(p1);
            printf("Toatal Leaf Nodes in BST: %d\n", n);
        }
        else if (ch == 7)
        {
            printf("Enter the delete Value: ");
            scanf("%d", &delval);
            del_doublePtr(&p1, delval);
        }
        else
        {
            break;
        }
    }
    return 0;
}
