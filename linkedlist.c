#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *ptr)
{
    int val;
    printf("Enter the Element you Want to create: ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if(ptr == NULL)
    {
        new->next = ptr;
        return new;
    }
    else
    {
        struct node *temp = ptr;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        return ptr;
    }
}
void Display(struct node *ptr)
{
    if ((ptr)==NULL)
    {
        printf("listis Empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void rev(struct node*ptr)
{
    if(ptr->next==NULL)
    {
        printf("%d",ptr->data);
    }
    else{
        rev(ptr->next);
        printf("%d",ptr->data);
    }
    printf("\n");
}
int main()
{
    int ch;
    struct node *start = NULL;
    while (1)
    {
        printf("\t\t\t\t1.create\n");
        printf("\t\t\t\t2.Display\n");
        printf("\t\t\t\t3.reverse print\n");
        printf("\t\t\t\t4.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            start = create(start);
        }
        else if (ch == 2)
        {
            Display(start);
        }
        else if(ch==3)
        {
            rev(start);
        }
        else
        {
            break;
        }
    }
    return 0;
}
