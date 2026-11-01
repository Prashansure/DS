#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

void insertBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted at end.\n");
}

void insertPosition()
{
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

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
            printf("Invalid Choice.\n");
        }

    } while (choice != 5);

    return 0;
}