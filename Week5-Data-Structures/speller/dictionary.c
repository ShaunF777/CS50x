// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define LENGTH 45 // Adjust based on the expected maximum word length
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary(means its spelled correctly), else false
bool check(const char *word) //must be case-insensitive
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (word == NULL)
        return 1;
    return toupper(word[0]) - 'A';
}

// Loads all dictionary words into a hash table, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    char *dword = NULL;
    // Read each word in the file one at a time
    while (fscanf(file, "%s", dword) != EOF) // will return EOF once it reaches end of file
    {
        // Hash word to obtain a hash value
        int bucket = hash(dword);
        if (bucket < 0 || bucket >= N)
        {
            printf("Invalid hash value for word: %s\n", dword);
            fclose(file); // Close the file before returning
            return false; // Return false if the hash value is invalid
        }

        // insert node into hash table at that location
        node *n = malloc(sizeof(node)); // Create a new node for each word
        if (n == NULL)
        {
            fclose(file); // Close the file before returning
            return false; // Return false if memory allocation fails
        }
        strcpy(n->word, dword); // will copy dword into node n's word field
        n->next = NULL;
        n->next = table[bucket]; // Link the new node to the existing list
        table[bucket] = n; // Insert the new node at the beginning of the list

    }

    // Close the dictionary file
    fclose(file);
    return true; // Return true if loading was successful
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
