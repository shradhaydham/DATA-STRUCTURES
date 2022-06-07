/*Queue using Linked List With Single Pointer*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *Enqueue(struct node *f)
{
    int val;
    printf("Enter the Value you want to Enqueue: ");
    scanf("%d", &val);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *itr = f;
    new->data = val;
    if (isEmpty(f))
    {
        f = new;
        new->next = NULL;
    }
    else
    {
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        new->next = itr->next;
        itr->next = new;
    }
    return f;
}

struct node* Dqueue(struct node *f){
    struct node *temp = f;
    if (isEmpty(f))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        free(temp);
        return f;
    }

}

void Display(struct node *f){
    if (isEmpty(f))
    {
        printf("Queue is Empty");
    }
    else
    {
        while (f != NULL)
        {
            printf("%d ",f->data);
            f = f->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    struct node *Front = NULL;
    while (1)
    {
        printf("\t\t\t\t1.Enqueue\n");
        printf("\t\t\t\t2.Dequeue\n");
        printf("\t\t\t\t3.Display\n");
        printf("\t\t\t\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        if (ch == 1)
        {
            Front = Enqueue(Front);
        }
        else if (ch == 2)
        {
            Front = Dqueue(Front);
        }
        else if (ch == 3)
        {
            Display(Front);
        }
        else
        {
            break;
        }

    }

    return 0;
}
