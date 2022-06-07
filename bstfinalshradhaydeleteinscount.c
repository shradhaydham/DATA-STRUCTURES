//binary tree delete count insert traverse
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

void countnode (struct node *ptr,int *count)
{

    if (ptr == NULL)
    {
        return;
    }
    else
    {
        (*count)++;
    }
        countnode (ptr->left,count);
        countnode (ptr->right,count);
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
             }
              countleafnode (ptr->left,countleaf);
              countleafnode (ptr->right,countleaf);
    }
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


void insertnode(struct node **root, int val)
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
            insertnode(&(*root)->left, val);
        }
        else
        {
            insertnode(&(*root)->right, val);
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

void deletenode(struct node **root, int val)
{
    if (*root == NULL)
    {
        printf("Node does not exist\n");
        return;
    }
    else if ((*root)->data > val)
    {
        deletenode(&(*root)->left, val);
    }
    else if ((*root)->data < val)
    {
        deletenode(&(*root)->right, val);
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

        deletenode(&(*root)->left, temp->data);
    }
}
void maxvalue(struct node *ptr)
{
    struct node*temp=ptr;
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        printf("%d",temp->data);
    }
}
void minvalue(struct node *ptr)
{
    struct node*temp=ptr;
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        printf("%d",temp->data);
    }
}
void findParent(struct node*ptr,int val,int parent)
{
    if(ptr==NULL)
    {
        return;
    }
     else
    {
        if(ptr->data==val)
        {
              printf("%d",parent);
        }
        else
        {
              findParent(ptr->left,val,ptr->data);
              findParent(ptr->right,val,ptr->data);
        }
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
        printf("\t\t\t\t8.find max value node\n");
        printf("\t\t\t\t9.find min value node\n");
        printf("\t\t\t\t10.find parent of node\n");
        printf("\t\t\t\t11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the Value: ");
            scanf("%d", &val);
            insertnode(&p1,val);
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
            int count=0;
            countnode(p1,&count);
            printf("%d",count);
        }
        else if (ch == 6)
        {
            int countleaf=0;
            countleafnode(p1,&countleaf);
            printf("%d",countleaf);
        }
        else if (ch == 7)
        {
            printf("Enter the delete Value: ");
            scanf("%d", &delval);
            deletenode(&p1, delval);
        }
        else if (ch == 8)
        {
           maxvalue(p1);
        }
        else if (ch == 9)
        {
           minvalue(p1);
        }
        else if (ch == 10)
        {
            int value,parent;
            printf("Enter the node to find parent: ");
            scanf("%d", &value);
            findParent(p1,value,parent);
        }
        else
        {
            break;
        }
    }
    return 0;
}
