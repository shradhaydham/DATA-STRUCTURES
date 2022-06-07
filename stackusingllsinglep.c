/*Stack using Linked List With Single Pointer*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};



int isEmpty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *Push(struct node *ptr)
{
    int val;
    printf("Enter the Element you Want to Push: ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->next = ptr;
    return new;
}

struct node *Pop(struct node *ptr)
{
    struct node *temp = ptr;
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        ptr = ptr->next;
        printf("%d Popped\n", temp->data);
        free(temp);
        return ptr;
    }
}

void Peek(struct node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top value of Stack: %d\n", ptr->data);
    }
}

void Display(struct node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
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

int main()
{
    int ch;
    struct node *top = NULL;
    while (1)
    {
        printf("\t\t\t\t1.Push\n");
        printf("\t\t\t\t2.Pop\n");
        printf("\t\t\t\t3.Peek\n");
        printf("\t\t\t\t4.Display\n");
        printf("\t\t\t\t5.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            top = Push(top);
        }
        else if (ch == 2)
        {
            top = Pop(top);
        }
        else if (ch == 3)
        {
            Peek(top);
        }
        else if (ch == 4)
        {
            Display(top);
        }
        else
        {
            break;
        }
    }
    return 0;
}
