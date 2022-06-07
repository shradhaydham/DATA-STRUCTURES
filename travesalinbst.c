#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* createNode(int data)
{
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
         inorder(root->left);
         printf("%d",root->data);
         inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
struct node*searchnode(struct node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return searchnode(root->left,key);
    }
    else
    {
        return searchnode(root->right,key);
    }
}
int main()
{
    struct node *p =createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
   // preorder(p);
   //  inorder(p);
   // postorder(p);

    struct node*n=searchnode(p,5);
    if(n!=NULL)
    {
        printf("node is found shradhay that is:%d",n->data);
    }
    else
    {
        printf("node not found");
    }
}
