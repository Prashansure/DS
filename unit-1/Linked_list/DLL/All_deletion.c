#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *newnode, *temp, *last;

void create()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            newnode->prev = NULL;
            head = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
        }
    }
}

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

void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        last = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

    printf("First node deleted.\n");
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        last = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        last = temp->prev;
        free(temp);
    }

    printf("Last node deleted.\n");
}

void deletePosition()
{
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    while (i < pos+1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        last = temp->prev;
        free(temp);
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    printf("Node deleted successfully.\n");
}

int main()
{
    int choice;

    create();

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Display\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Given Position\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            deleteBeginning();
            display();
            break;

        case 3:
            deleteEnd();
            display();
            break;

        case 4:
            deletePosition();
            display();
            break;

        case 5:
            printf("Program Ended.Thankuuuu\n");
            break;

        default:
            printf("Invalid Choice.\n");
        }

    } while (choice != 5);

    return 0;
}