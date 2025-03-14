#pragma once
// bst.h - Header file for the Binary Search Tree
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure for the BST
typedef struct Node {
    char data;
    struct Node* left, * right;
} Node;

// Function prototypes
Node* insert(Node* root, char data);
Node* search(Node* root, char key);
int countNodes(Node* root);
int treeHeight(Node* root);
void inOrderPrint(Node* root);
void freeTree(Node* root);

#endif // BST_H