//circular processes deletion
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int pr_num;
    int data;
    struct node *next;
};
void insertnode(struct node **ptr,int n)
{
    int val;
    printf("enter the time req by process:");
    scanf("%d",&val);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->pr_num=n;
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
void display(struct node *ptr)
{
  if(ptr==NULL)
  {
      printf("list is empty");
  }
  else
    {
        struct node *temp=ptr->next;
         while(temp!=ptr)
         {
             printf("%d",temp->data);
             temp=temp->next;
         }
          printf("%d",temp->data);
           printf("\n");
    }
}
void cal_time(struct node *ptr)
{
    int min_time;
    printf("enter the time alotted for process:");
    scanf("%d",&min_time);
    printf("the processes are as followed");
    display(ptr);
    struct node *itr=ptr;
    struct node *temp=itr->next;
    while (temp!=NULL)
    {
        if(temp->data<= min_time)
        {
            if(temp->next==temp)
            {
            printf("process no %d completed\n",temp->pr_num);
            temp=NULL;
            }
            else
            {
                printf("process no %d completed\n",temp->pr_num);
                temp=temp->next;
                itr->next=temp;
            }
        }
        else
        {
            temp->data=temp->data-min_time;
            temp=temp->next;
            itr=itr->next;
        }
    }

}



int main()
{
    int ch;
    int n = 0;
    struct node *head = NULL;
    while (1)
    {
        printf("\t1.Insert\n");
        printf("\t2.Calculate Process Time\n");
        printf("\t3.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        if( ch== 1)
        {
            n++;
            insertnode(&head,n);
        }
        else if(ch==2)
        {
            cal_time(head);
        }
        else{
            break;
        }
    }
    return 0;
}
