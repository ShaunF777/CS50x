#include <cs50.h>
#include <ctype.h> // word character id
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // stringlength

char ciphert(char text, int key);

// Alphindex assigned to each letter of the alphabet
//                  A  B  C  D  E  F  G  H  I  J   K  L   M   N   O   P   Q   R   S   T   U   V   W
//                  X   Y   Z
int alphaindex[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
                    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

int main(int argc, string argv[])
// argc is the number of inputs the prog receives including program name
// if typing ./caesar 8, then argc = 2 & argv containes 2 strings, argv[0] = ./caesar & argv[1] = 8
{
    // Get key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // return 1 means something whent wrong
    }
    else
    {
        // loop will iterate over each character in argv[1] until it reaches the end - null
        // character ('\0')
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            // use isdigit(argv[1][i]) to check if the character at position i is a digit
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    int key = atoi(argv[1]); // use atoi function to convert argv[1] to integer
    // segmentation faults ocur when looking too far in an array argv[1] assumes i have 2 arguments

    // Get plaintext
    string ptext = get_string("plaintext: ");
    char ctext[100];
    int length = strlen(ptext);
    // Encipher
    for (int i = 0; i < length; i++)
    {
        ctext[i] = ciphert(ptext[i], key);
    }
    // end of ctext must have /0 finalise the character string
    ctext[length + 1] = '\0';

    // Print ciphertext
    printf("ciphertext: %s\n", ctext);
}

char ciphert(char text, int key)
{
    char newtext;
    if (isupper(text))
    {
        int ai = alphaindex[text - 'A'];
        // if char has value of 65 up to 90(A - Z)
        // Cipherchar[i] = (plaintext[i] + key) % 26
        int shift = (ai + key) % 26;
        newtext = (char) shift + 'A';
        return newtext;
    }
    else if (islower(text))
    {
        int ai = alphaindex[text - 'a'];
        // if char has value of 97 up to 122(a - z)
        int shift = (ai + key) % 26;
        newtext = (char) shift + 'a';
        return newtext;
    }
    else if (isalpha(text) == 0)
    {
        newtext = text;
        return newtext;
    }
    return 1;
}
