//Circular Linked List
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
        struct node *temp=ptr->next;
        while(temp!=ptr)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}
void insert_Node(struct node **ptr)
{
    int val;
    printf("Enter the Value of Node: ");
    scanf("%d",&val);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    if(*ptr==NULL)
    {
        new->next=new;
    }
    else
    {
        new->next=(*ptr)->next;
        (*ptr)->next=new;
    }
    *ptr=new;
}
void delete_Node(struct node **ptr)
{
    int val;
    printf("Enter the Value of Node you Wish to Delete: ");
    scanf("%d",&val);
    struct node *temp=*ptr;
    if(*ptr==NULL)
    {
        printf("List is Empty\n");
    }
    else if((*ptr)->data==val)
    {
        printf("Node Found and Deleted\n");
        if((*ptr)->next==*ptr)
        {
            *ptr = NULL;
        }
        else
        {
            while(temp->next!=*ptr)
            {
                temp=temp->next;
            }
            *ptr=temp;
            temp=temp->next;
            (*ptr)->next=temp->next;
            free(temp);
        }
    }
    else
    {
        struct node *delNode=(*ptr)->next;
        while (delNode!=(*ptr) && delNode->data!=val)
        {
            temp=temp->next;
            delNode=delNode->next;
        }
        if (delNode==(*ptr))
        {
            printf("Node Not Found\n");
        }
        else
        {
            printf("Node Found and Deleted\n");
            temp->next=delNode->next;
            free(delNode);
        }
    }
}

int main()
{
    int ch;
    struct node *head=NULL;
    while(1)
    {
        printf("\t1.Insert a Node\n");
        printf("\t2.Search and Delete\n");
        printf("\t3.Display List\n");
        printf("\t4.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_Node(&head);
                break;
            case 2:
                delete_Node(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Input.");
                break;
        }
    }
    return 0;
}
