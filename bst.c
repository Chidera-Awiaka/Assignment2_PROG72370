// bst.c - Implementation file for the Binary Search Tree
#include "bst.h"

// Function to create a new node
Node* createNode(char data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a character into the BST
Node* insert(Node* root, char data) 
{
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search for a character in the BST
Node* search(Node* root, char key)
{
    if (root == NULL || root->data == key) return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Count the number of nodes in the BST
int countNodes(Node* root) 
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Determine the height of the BST
int treeHeight(Node* root) 
{
    if (root == NULL) return -1; // Height of empty tree is -1
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Print the BST in in-order traversal (sorted order)
void inOrderPrint(Node* root) {
    if (root != NULL) {
        inOrderPrint(root->left);
        printf("%c ", root->data);
        inOrderPrint(root->right);
    }
}

// Free allocated memory for the BST
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
