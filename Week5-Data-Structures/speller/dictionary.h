// Declares a dictionary's functionality

#ifndef DICTIONARY_H /* If not defined, include the following code, up to #endif */
#define DICTIONARY_H

#include <stdbool.h> // Where bool itself is defined (without CS50.h)

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45 // LENGTH's value will be replaced by 45 throughout the code
// It’s not a variable, just a find-and-replace trick.

// Prototypes
bool check(const char *word); // const string 'word' will not be changed in function
unsigned int hash(const char *word); // const string 'word' will not be changed in function
bool load(const char *dictionary); // const string 'dictionary' will not be changed in function
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
