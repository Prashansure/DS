#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;

    int choice = 1, item, flag = 0, pos = 1;

    head = NULL;

    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data : ");
        scanf("%d",&newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1) : ");
        scanf("%d",&choice);
    }

    printf("\nLinked List : ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n\nEnter element to search : ");
    scanf("%d",&item);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == item)
        {
            printf("%d found at position %d\n", item, pos);
            flag = 1;
        }

        temp = temp->next;
        pos++;
    }

    if(flag == 0)
    {
        printf("%d not found", item);
    }

    return 0;
}