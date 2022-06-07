/*Stack using Linked List With Double Pointer */
/*shradhay dham*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void Push(struct node **ptr){
    int val;
    printf("Enter the value you want to Enter: ");
    scanf("%d",&val);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->next = *ptr;
    *ptr = new;
}

void Pop(struct node **ptr){
    struct node *temp = *ptr;
    if ((*ptr)==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        (*ptr) = (*ptr)->next;
        printf("%d is Popped From the Stack\n",temp->data);
        free(temp);
    }
}

void Peek(struct node *ptr){
    if ((ptr)==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is: %d\n",ptr->data);
    }
}

void Display(struct node *ptr){
    if ((ptr)==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n",ptr->data);
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
            Push(&top);
        }
        else if (ch == 2)
        {
            Pop(&top);
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
