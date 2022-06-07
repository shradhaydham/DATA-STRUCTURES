#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *ptr)
{
    if (ptr==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
void insert_node(struct node **ptr)
{
    int val;
    printf("Enter the Value of Node: ");
    scanf("%d",&val);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=*ptr;
    *ptr=new;
}
void rev(struct node *ptr)
{
    if(ptr->next == NULL)
    {
        printf("%d",ptr->data);

    }
    else
    {
        rev(ptr->next);
        printf("%d",ptr->data);
    }
     printf("\n");
}

int main()
{
    int ch;
    struct node *head=NULL;
    while(1)
    {
        printf("\t1.insert a node\n");
        printf("\t2.display list\n");
        printf("\t3.display in reverse order\n");
        printf("\t4.exit\n");
        printf("\tenter your choice");
        scanf("%d",&ch);
        if(ch == 1)
        {
            insert_node(&head);
        }
        else if(ch == 2)
        {
            display(head);
        }
        else if(ch == 3)
        {
            rev(head);
        }
        else
        {
            break;
        }
    }
    return 0;
}
