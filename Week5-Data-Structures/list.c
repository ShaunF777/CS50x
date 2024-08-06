#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase; 
    struct node *next;
} node;

#define LIST_SIZE 4

bool unload(node *list); // Free alocated nodes
void visualizer(node *list);

int main(void)
{
    // Remember singly linked lists, has the back most node allocated 1st
    node *list = NULL; // Just so it can be attached at the front later

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->phrase = phrase;
        n->next = NULL;
        n->next = list;
        list = n;

        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}
// Always run with valgrind ./list , to make sure there's not memory leaks
bool unload(node *list)
{
    // TODO: Free all allocated nodes and return true
    node *ptr = list; // ptr now points to the front/latest node just to have a value
    while (list != NULL)
    {
        ptr = list->next; //ptr now points to the next node we want to free after we've freed the front ( node
        free(list); // Free the 2nd node
        list = ptr; // List now points to the 1st node
    }
    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL) // till we reach the NULL pointer
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}

/*  node *n = malloc(sizeof(node)); // Create first node area for linked list to start
    n->phrase = "Hi!"; // Define phrase within this node, calling the phrase attibute of n = HI
    n->next = NULL; // Initially NULL, but on later nodes to form the chain refrencing backwards
    list = n; //List now also points to n, so we can add to the front of the chain

    // Add new node or 2nd node
    n = malloc(sizeof(node)); // Allocate new space for 2nd node
    n->phrase = "Hey!";
    n->next = list; // Now this 2nd node is linked with the 1st node wich 'list' is pointing to
    list = n; // Now 'list' points to the front/2nd node

    // To free nodes, add a reference pointer to allow going back and freeing node for node, front to back
    node *ptr = list->next; // ptr now points to the next node we want to free after we've freed the front (prv) node
    free(list); // Free the 2nd node
    list = ptr; // List now points to the 1st node
    ptr = list->next; // This ensures we could access the next node going back, till we reach the 1st node with NULL in its next attibute
    free(list); // Now free the 1str node
    list = ptr; // Repeat the process to make sure we free all nodes till the 1st one
*/
