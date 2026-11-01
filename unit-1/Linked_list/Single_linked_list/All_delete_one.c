#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL, *newnode, *temp, *prev;

void create() {
	int n, i;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			temp = newnode;
		} else {
			temp->next = newnode;
			temp = newnode;
		}
	}
}

void display() {
	temp = head;
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}
	printf("Linked List: ");
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void deleteBeginning() {
	if (head == NULL) {
		printf("List is empty.\n");
	} else {
		temp = head;
		head = head->next;
		free(temp);
		printf("First node deleted.\n");
	}
}

void deleteEnd() {
	if (head == NULL) {
		printf("List is empty.\n");
	} else if (head->next == NULL) {
		free(head);
		head = NULL;
		printf("Last node deleted.\n");
	} else {
		temp = head;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
		printf("Last node deleted.\n");
	}
}

void deletePosition() {
	int pos, i = 1;
	struct node *nextnode;
	printf("Enter position to delete: ");
	scanf("%d", &pos);
	if (head == NULL) {
		printf("List is empty.\n");
	} else if (pos == 1) {
		deleteBeginning();
	} else {
		temp = head;
		while (i < pos - 1 && temp != NULL) {
			temp = temp->next;
			i++;
		}
		if (temp == NULL || temp->next == NULL) {
			printf("Invalid position.\n");
		} else {
			nextnode = temp->next;
			temp->next = nextnode->next;
			free(nextnode);
			printf("Node deleted.\n");
		}
	}
}

int main() {
	int choice;
	create();
	do {
		printf("\n----- MENU -----\n");
		printf("1. Display\n");
		printf("2. Delete at Beginning\n");
		printf("3. Delete at End\n");
		printf("4. Delete at Position\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
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
				printf("Program Ended.\n");
				break;
			default:
				printf("Invalid Choice.\n");
		}
	} while (choice != 5);
	return 0;
}
