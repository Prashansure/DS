#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *newnode, *temp;

void display()
{
    temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at beginning.\n");
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

void insertPosition()
{
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;

        head = newnode;
    }
    else
    {
        temp = head;

        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid Position\n");
            free(newnode);
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }

    printf("Node inserted successfully.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Given Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            display();
            break;

        case 2:
            insertEnd();
            display();
            break;

        case 3:
            insertPosition();
            display();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program Ended.\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 5);

    return 0;
}