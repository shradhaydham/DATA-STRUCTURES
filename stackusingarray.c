//stackusing array
#include <stdio.h>
#define max 10
int push(int [],int);
int pop(int [],int);
void display(int [],int);
void peek(int [],int);
int main()
{
    int stack[max],top=-1,ch;
   while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            top=push(stack,top);
            break;
            case 2:
            top=pop(stack,top);
            break;
            case 3:
            display(stack,top);
            break;
            case 4:
            peek(stack,top);
            break;
            case 5:
            exit(0);
            break;
        }
    }
}
int push(int stack[],int top)
{
    int x;
    if(top==max-1)
    printf("Stack overflow");
    else
    {
        printf("Enter the element to be pushed ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    return top;
}
int pop(int stack[],int top)
{
    int x;
    if(top==-1)
    printf("Empty stack");
    else
    {
        x=stack[top];
        top--;
        printf(" pooped element %d\n",x);
    }
    return top;
}
void display(int stack[],int top)
{
    if(top==-1)
    printf("Empty stack");
    else
    {
        while(top!=-1)
        {
        printf("%d ",stack[top]);
        top--;
        }
    }
}
void peek(int stack[],int top)
{
    if(top==-1)
    printf("Empty stack");
    else
    printf("%d",stack[top]);
}
