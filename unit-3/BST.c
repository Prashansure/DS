#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search an element
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// Find maximum node
struct Node* findMax(struct Node* root) {
    while (root != NULL && root->right != NULL)
        root = root->right;

    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node has no child or one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right =
            deleteNode(root->right, temp->data);
    }

    return root;
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Display BST
    printf("BST Inorder Traversal: ");
    inorder(root);

    // Search
    int key = 40;

    if (search(root, key) != NULL)
        printf("\n%d is found in BST", key);
    else
        printf("\n%d is not found in BST", key);

    // Minimum
    struct Node* min = findMin(root);
    printf("\nMinimum value: %d", min->data);

    // Maximum
    struct Node* max = findMax(root);
    printf("\nMaximum value: %d", max->data);

    // Delete
    printf("\n\nDeleting 30..."); 
    root = deleteNode(root, 30);

    printf("\nBST after deletion: ");
    inorder(root);

    return 0;  
}