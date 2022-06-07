#include <stdio.h>
#define max 50
void insert();
void delete();
void display();
void peek();

    int queue[max],front=-1,rear=-1;
    int main()
           {
               int ch;
                  do{
          printf("\nwhich operation you like to perform\n1.insert\n2.delete\n3.display\n4.peek\n5.exit\n");
              scanf("%d",&ch);
                 switch(ch)
                 {
                 case 1:
                    insert();
                    break;
                 case 2:
                delete();
                    break;
                 case 3:
                    display();
                    break;
                 case 4:
                    peek();
                    break;
                 }
      }while(ch<=4);
}
void insert()
{
    int x;
    if(rear == max-1)
    printf("queue is full\n");
    else{
        if(front == -1)
        front=0;
        printf("enter element to be inserted\n");
        scanf("%d",&x);
        rear = rear + 1;
        queue[rear]=x;

    }
}
    void delete()
    {
        int x;
        if(front==-1|| front>rear)
        printf("queue is empty\n");
        else
            printf("element deleted is : %d\n",queue[front]);
        }
void display()
        {
            if(front==-1|| front>rear)
        printf("queue is empty\n");
        else
        {
            while(front>=-1)
            {
            printf("%d\n",queue[front]);
        front--;
        }

    }
        }
        void peek()
        {
           if(front==-1|| front>rear)
        printf("queue is empty\n");
        else
            printf("%d\n",queue[front]);
        }
