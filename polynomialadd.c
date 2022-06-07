//add two polynomial
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int co_ef;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dX**%d ", ptr->data, ptr->co_ef);
        ptr = ptr->next;
    }
    printf("\n");
}

void push(struct node **ptr)
{
    int val, coef;
    printf("Enter the value: ");
    scanf("%d", &val);
    printf("Enter the coefficient value: ");
    scanf("%d", &coef);
    struct node *temp = *ptr;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->co_ef = coef;
    if (temp == NULL)
    {
        new->next = temp;
        *ptr = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void push_elem(struct node **ptr, int val, int coef)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->co_ef = coef;
    new->next = *ptr;
    *ptr = new;
}

void rev(struct node **ptr)
{
    struct node *curr = *ptr;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        struct node *ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }
    *ptr = prev;
}

void Add(struct node *l1, struct node *l2, struct node **itr)
{
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->co_ef == l2->co_ef)
        {
            push_elem(itr, (l1->data + l2->data), l1->co_ef);
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->co_ef > l2->co_ef)
        {
            push_elem(itr, l1->data, l1->co_ef);
            l1 = l1->next;
        }
        else
        {
            push_elem(itr, l2->data, l2->co_ef);
            l2 = l2->next;
        }
    }
    if (l1 == NULL)
    {
        while (l2 != NULL)
        {
            push_elem(itr, l2->data, l2->co_ef);
            l2 = l2->next;
        }
    }
    else
    {
        while (l1 != NULL)
        {
            push_elem(itr, l1->data, l1->co_ef);
            l1 = l1->next;
        }
    }
    rev(itr);
    display(*itr);
}

int main()
{
    struct node *l1 = NULL;
    struct node *l2 = NULL;
    struct node *sum = NULL;
    int ch;
    while (1)
    {
        printf("\t\t\t\t1.Push values in 1st Polynomial\n");
        printf("\t\t\t\t2.Push values in 2nd Polynomial\n");
        printf("\t\t\t\t3.Add Polynomials\n");
        printf("\t\t\t\t4.Break\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            push(&l1);
        }
        else if (ch == 2)
        {
            push(&l2);
        }
        else if (ch == 3)
        {
            Add(l1, l2, &sum);
        }

        else
        {
            break;
        }
    }
}
