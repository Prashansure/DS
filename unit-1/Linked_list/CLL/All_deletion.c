#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create Circular Linked List */
void create()
{
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while(temp->next != head)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = head;
        }
    }
}

/* Count Nodes */
int countNodes()
{
    if(head == NULL)
        return 0;

    int count = 1;
    struct node *temp = head;

    while(temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/* Display List */
void display()
{
    if(head == NULL)
    {
        printf("\nList is Empty.\n");
        return;
    }

    struct node *temp = head;

    printf("\nHEAD -> ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("HEAD\n");
    printf("Total Nodes = %d\n", countNodes());
}

/* Delete Beginning */
void deleteBeginning()
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *last = head;

        while(last->next != head)
            last = last->next;

        struct node *first = head;

        head = head->next;
        last->next = head;

        free(first);
    }

    printf("First node deleted successfully.\n");
}

/* Delete End */
void deleteEnd()
{
    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;

        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Last node deleted successfully.\n");
}

/* Delete at Position */
void deletePosition()
{
    int pos, i;

    if(head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Enter Position: ");
    scanf("%d", &pos);

    int count = countNodes();

    if(pos < 1 || pos > count)
    {
        printf("Invalid Position.\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeginning();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for(i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully.\n");
}

/* Free Entire List */
void freeList()
{
    while(head != NULL)
        deleteBeginning();
}

/* Main Function */
int main()
{
    int choice;

    create();

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Display\n");
        printf("2. Delete Beginning\n");
        printf("3. Delete End\n");
        printf("4. Delete Position\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
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
                freeList();
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    }
    while(choice != 5);

    return 0;
}