/*Queue using Linked List With Double Pointer*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *f, struct node *r)
{
    if (f == NULL && r == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(struct node **f, struct node **r)
{
    int val;
    printf("Enter the value you want to Enqueue: ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if (isEmpty(*f, *r))
    {
        *f = *r = new;
        (*r)->next = NULL;
    }
    else
    {
        new->next = (*r)->next;
        (*r)->next = new;
        *r = new;
    }
}

void Dequeue(struct node **f, struct node **r)
{
    struct node *temp = *f;
    if (isEmpty(*f, *r))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if (*f == *r)
        {
            *f = *r = NULL;
        }
        else
        {
            *f = (*f)->next;
            free(temp);
        }
    }
}

void Display(struct node *f, struct node *r)
{
    if (isEmpty(f, r))
    {
        printf("Queue is Empty");
    }
    else
    {
        while (f != NULL)
        {
            printf("%d ", f->data);
            f = f->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    struct node *Front = NULL;
    struct node *Rear = NULL;
    while (1)
    {
        printf("\t\t\t\t1.Enqueue\n");
        printf("\t\t\t\t2.Dequeue\n");
        printf("\t\t\t\t3.Display\n");
        printf("\t\t\t\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            Enqueue(&Front, &Rear);
        }
        else if (ch == 2)
        {
            Dequeue(&Front, &Rear);
        }
        else if (ch == 3)
        {
            Display(Front, Rear);
        }
        else
        {
            break;
        }
    }
    return 0;
}
