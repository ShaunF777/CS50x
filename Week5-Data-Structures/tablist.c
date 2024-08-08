// Not working merge, please compare with the working file = hash.c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;

node *table[26];
#define LIST_SIZE 4

int hash(string phrase);
bool unload(node *list); // Free alocated nodes
void visualizer(node *list);

int main(void)
{
    // Remember singly linked lists, has the back most node allocated 1st
    table[] = {NULL}; // Just so it can be attached at the front later

    // Add items
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);

        node *n = malloc(sizeof(node));
        //if (n == NULL)// double check if the memory exists
            //return 1; // if not then quit

        n->phrase = phrase; // insert phrase we saved
        n->next = NULL; // preset to NULL = best prectice
        n->next = table[bucket]; // n->next now points to NULL, this new node now points to the previous one
        table[bucket] = n; // list now points to what n was pointing to, 1st node, then 2nd node, etc.


        // Visualize list after adding a node.
        visualizer(table[bucket]);
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

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    //return (phrase % (sizeof(table)/sizeof(table[0])));
    printf("This is the phrase converted to integer: %i\n", phrase[0] - 'A');
    return toupper(phrase[0]) - 'A'; // Subtracts ASCII 65 from the 1st letter, a - A = 0, c - A = 2
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
