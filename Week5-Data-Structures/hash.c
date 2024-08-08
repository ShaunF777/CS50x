/* From Section - Working hashtable (adding list.c to table.c) */
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
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    //memset(table, 0, sizeof(table)); // this initializes all elements to NULL
    for (int i=0; i<26; i++)
        table[i] = NULL; /* Initialize all of them to NULL */

    // Hash & Add items
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        int bucket = hash(phrase);
        if (bucket < 0)
        {
            printf("Invalid phrase input.\n");
            continue; // skip this iteration
        }
        printf("%s hashes to %i\n", phrase, bucket);

        node *n = malloc(sizeof(node));
        if (n == NULL)// double check if the memory exists
            return 1; // if not then quit

        n->phrase = phrase;
        n->next = NULL;
        n->next = table[bucket];
        table[bucket] = n;

        visualizer(table[bucket]);
    }
    for (int i = 0; i < 26; i++)
    {
        if (!unload(table[i]))
        {
            printf("Error freeing the list.\n");
            return 1;
        }
    }
    printf("Freed the list.\n");
    return 0;
}


int hash(string phrase)
{
    if (phrase == NULL || !isalpha(phrase[0]))
    {
        return 1;
    }
    printf("This is the phrase converted to integer: %i\n", phrase[0] - 'A');
    return toupper(phrase[0]) - 'A';
}


bool unload(node *list)
{
    node *ptr = list;
    while (list != NULL)
    {
        ptr = list->next;
        free(list);
        list = ptr;
    }
    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
