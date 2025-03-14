// main.c - Main file to test the Binary Search Tree
#include "bst.h"

#define MIN_CHARS 11
#define MAX_CHARS 20

int main()
{
    Node* root = NULL;

    srand(time(NULL)); // Seed random number generator
    int numChars = (rand() % (MAX_CHARS - MIN_CHARS + 1)) + MIN_CHARS;

    char* insertedChars = (char*)malloc(numChars * sizeof(char)); // Allocates the memory dynamically
    if (insertedChars == NULL)
    {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Inserting characters: ");
    for (int i = 0; i < numChars; i++)
    {
        char randomChar = 'a' + (rand() % 26);
        insertedChars[i] = randomChar;
        root = insert(root, randomChar);
        printf("%c ", randomChar);
    }
    printf("\n");

    printf("Sorted characters (in-order traversal): ");
    inOrderPrint(root);
    printf("\n");

    printf("Number of nodes: %d\n", countNodes(root));
    printf("Tree height: %d\n", treeHeight(root));

    free(insertedChars); // Free dynamically allocated memory
    freeTree(root); // Free tree memory
    return 0;
}
