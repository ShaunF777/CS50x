#include <cs50.h>
#include <ctype.h> // word character id
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // stringlength

char ciphert(char text, string key);

// New uppercase tested key
char capskey[26];

int main(int argc, string argv[])
{

    // always validate argc first to avoid segmentation faults
    if (argc != 2)
    {
        printf("Usage: ./substitution 26-alphabetic-key\n");
        return 1; // return 1 means something whent wrong
    }
    // only after checking argc value, then look into argv[1 or 2 or 3]
    int length = strlen(argv[1]);
    int duplkey = 0;
    if (length == 26)
    {
        // loop will iterate over each character in argv[1] until it reaches the end - null
        // character ('\0')
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            // use isdigit(argv[1][i]) to check if the character at position i is a digit
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            capskey[i] = toupper(argv[1][i]);
        }
    }
    else
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    if (length == 26)
    {
        for (int h = 0; h < length; h++)
        {
            for (int j = h + 1; j < length; j++)
            {
                if (capskey[h] == capskey[j])
                {
                    duplkey += 1;
                }
            }
        }
        if (duplkey != 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    // Get plaintext
    string ptext = get_string("plaintext: ");
    char ctext[100];
    int lengthpt = strlen(ptext);
    // Encipher
    for (int i = 0; i < lengthpt; i++)
    {
        ctext[i] = ciphert(ptext[i], capskey);
    }
    // end of ctext must have /0 finalise the character string
    ctext[lengthpt + 1] = '\0';

    // Print ciphertext
    printf("ciphertext: %s\n", ctext);
    return 0;
}

char ciphert(char text, string key)
{
    char newtext;
    if (isupper(text))
    {
        int index = (int) text - 'A';
        newtext = key[index];
        return newtext;
    }
    else if (islower(text))
    {
        int index = (int) text - 'a';
        newtext = tolower(key[index]);
        return newtext;
    }
    else if (isalpha(text) == 0)
    {
        newtext = text;
        return newtext;
    }
    return 1;
}
