// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

// Undefine any definitions
#undef calculate
#undef getrusage

// Default dictionary
#define DICTIONARY "dictionaries/large"

// Prototype
double calculate(const struct rusage *b, const struct rusage *a);

int main(int argc, char *argv[])
{
    // Check for correct number of args
    if (argc != 2 && argc != 3) // Can be run with just the text file, because of default dictionary
    {
        printf("Usage: ./speller [DICTIONARY] text\n");
        return 1;
    }

    // Structures for timing data, taking a timestamp before and after
    // It is used to get resource usage statistics for the calling process, its children, or threads.
    struct rusage before, after;

    // Benchmarks
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    // Determine dictionary to use
    // either custom dictionary (argv[1]), or else DICTIONARY "dictionaries/large"
    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;

    // Load dictionary
    getrusage(RUSAGE_SELF, &before); // get resource usage before we load
    bool loaded = load(dictionary); // load dictionary
    getrusage(RUSAGE_SELF, &after); // get resource usage after weve loaded, to analyze performance

    // Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    // Calculate time to load dictionary, Function returns number of seconds between b and a
    time_load = calculate(&before, &after); // Likely subtracts before from after, to give us the time difference

    // Try to open text
    // prepare a copy of the text string, using custom dict(argv[2]) or default dict(argv[1])
    char *text = (argc == 3) ? argv[2] : argv[1];
    FILE *file = fopen(text, "r"); // Open the text copy for reading
    if (file == NULL)
    {
        printf("Could not open %s.\n", text);
        unload();
        return 1;
    }

    // Prepare to report misspellings
    printf("\nMISSPELLED WORDS\n\n");

    // Prepare to spell-check
    int index = 0, misspellings = 0, words = 0;
    // index = array index for each word's chars as we go through text
    char word[LENGTH + 1];

    // Spell-check each word in text
    char c;
    while (fread(&c, sizeof(char), 1, file)) // Reads one character from the file and stores it in the variable c
    { // The while loop continues as long as fread successfully reads a character & stops when it reaches the end
    //of the file or encounters an error.
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0)) //  if c is an alphabetic character, or if c is a single quote
        {//and index is greater than zero.
            // Append character to word
            word[index] = c;
            index++;

            // Ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // Consume remainder of alphabetical string
                while (fread(&c, sizeof(char), 1, file) && isalpha(c));
                /* If it encounters a character that is not a letter, it stops reading.The semicolon at the end of the statement
                indicates that this loop doesn't have a body, so it just keeps looping until the condition becomes false. */

                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers (like MS Word can)
        else if (isdigit(c)) // If 'c' is 0 - 9
        {
            // Consume remainder of alphanumeric string
            while (fread(&c, sizeof(char), 1, file) && isalnum(c));
            /*  Continues as long as both fread successfully reads a character and isalnum returns true for that character.
            If fread fails to read a character (like at end of file), or if the character read is not alphanumeric, the loop will stop.
            The semicolon at the end indicates that this loop doesn't have a body, so it just keeps reading and discarding alphanumeric characters.*/

            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // Terminate current word
            word[index] = '\0';

            // Update counter
            words++;

            // Check word's spelling
            getrusage(RUSAGE_SELF, &before);
            bool misspelled = !check(word);
            getrusage(RUSAGE_SELF, &after);

            // Update benchmark
            time_check += calculate(&before, &after); // Returns number of seconds between b and a

            // Print word if misspelled
            if (misspelled)
            {
                printf("%s\n", word);
                misspellings++;
            }

            // Prepare for next word
            index = 0;
        }
    }

    // Check whether there was an error
    if (ferror(file))
    {
        fclose(file);
        printf("Error reading %s.\n", text);
        unload();
        return 1;
    }

    // Close text
    fclose(file);

    // Determine dictionary's size
    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to determine dictionary's size
    time_size = calculate(&before, &after); // Returns number of seconds between b and a

    // Unload dictionary
    getrusage(RUSAGE_SELF, &before);
    bool unloaded = unload();
    getrusage(RUSAGE_SELF, &after);

    // Abort if dictionary not unloaded
    if (!unloaded)
    {
        printf("Could not unload %s.\n", dictionary);
        return 1;
    }

    // Calculate time to unload dictionary
    time_unload = calculate(&before, &after); // Returns number of seconds between b and a

    // Report benchmarks
    printf("\nWORDS MISSPELLED:     %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", n);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n\n",
           time_load + time_check + time_size + time_unload);

    // Success
    return 0;
}

// Returns number of seconds between b and a
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        // ru_utime is the structure that holds the user CPU time used and tv_sec and tv_usec are the seconds and microseconds components of this time respectively
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) - // This is calculating the total user time for 'a' in microseconds.
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) + // This is doing the same for 'b', it gives the change in user time from 'b' to 'a'.
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) - // The same process is repeated for system time (ru_stime)
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec))) // Differences in user and system time are added together to give the total change in CPU time from 'b' to 'a'
                / 1000000.0); // Divided by 1,000,000 to convert the time from microseconds back to seconds before it is returned by the function
    }
}
