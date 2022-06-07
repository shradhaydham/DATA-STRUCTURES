//create polynomial
//shradhay dham
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int power;
    struct node*next;
};
void insert(struct node**ptr)
{
    int coeff;
    int pov;
    printf("enter the coefficient of polynomial\n");
    scanf("%d",&coeff);
    printf("enter the power of polynomial\n");
    scanf("%d",&pov);
    struct node*temp=(*ptr);
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=coeff;
    new->power=pov;
    if(temp==NULL)
    {
        new->next=temp;
        *ptr=new;
    }
    else
    {

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
    }
}
void display(struct node*ptr)
{
    while(ptr!=NULL)
    {
            printf("%dX*%d",ptr->data,ptr->power);
            ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node*head=NULL;
    int ch;
    while(1)
    {
        printf("\t\t\t\t1.insert in polynomial\n");
        printf("\t\t\t\t2.dispay polynomial\n");
        printf("\t\t\t\t3.exit\n");
        printf("enter your choice ");
        scanf("%d",&ch);
        if(ch==1)
        {
            insert(&head);
        }
        else if(ch==2)
        {
            display(head);
        }
        else
        {
            break;
        }

    }
    return 0;
}
