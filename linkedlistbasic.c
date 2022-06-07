#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *ptr,int val)
{

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
void splitlist(struct node *ptr,struct node **odd,struct node **even)
{
    int c=1;
    while(ptr!=NULL)
    {
        if(c%2==1)
        {
            *odd=create(*odd,ptr->data);
        }
        else
        {
            *even=create(*even,ptr->data);
        }
        c++;
        ptr=ptr->next;
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
void largestinfo(struct node*ptr)
{
    int max=0;
    while(ptr!=NULL)
    {
         if(ptr->data>max)
          max = ptr-> data;
          ptr=ptr->next;
   }
   printf("%d",max);
}
void alternate(struct node*ptr)
{
    if(ptr==NULL)
    {
        printf("list is empty");
    }
    else
    {
        while(ptr!=NULL && ptr->next!=NULL && (ptr->next)->next!=NULL)
            {
               printf("%d",ptr->data);
               ptr=(ptr->next)->next;
            }
            if(ptr!=NULL || ptr->next!=NULL || (ptr->next)->next!=NULL)
            printf("%d",ptr->data);
    }
}
void middle(struct node *ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count%2==0)
    {
        for(int i=0;i<(count/2);i++)
        {
            ptr=ptr->next;
        }
         printf("%d",ptr->data);
         ptr=ptr->next;
         printf("%d",ptr->data);
    }
    else
    {
        for(int i=0;i<((count+1)/2);i++)
        {
            ptr=ptr->next;
        }
         printf("%d",ptr->data);
    }
}
int main()
{
    int ch;
    struct node *start = NULL;
    struct node *odd = NULL;
    struct node *even= NULL;
    while (1)
    {
        printf("\t\t\t\t1.create\n");
        printf("\t\t\t\t2.Display\n");
        printf("\t\t\t\t3.reverse print\n");
        printf("\t\t\t\t4.alternate node print\n");
        printf("\t\t\t\t5. print middle node\n");
        printf("\t\t\t\t6. largest info\n");
        printf("\t\t\t\t7. split odd even\n");
        printf("\t\t\t\t8.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            int val;
                    printf("Enter the Element you Want to create: ");
                     scanf("%d", &val);
            start = create(start,val);
        }
        else if (ch == 2)
        {
            Display(start);
        }
        else if(ch == 3)
        {
            rev(start);
        }
        else if(ch == 4)
        {
            alternate(start);
        }
        else if(ch==5)
        {
            middle(start);
        }
        else if(ch==6)
        {
            largestinfo(start);
        }
         else if(ch==7)
        {
            splitlist(start,&odd,&even);
            Display(odd);
            printf("\n");
            Display(even);
        }
        else
        {
            break;
        }
    }
    return 0;
}
