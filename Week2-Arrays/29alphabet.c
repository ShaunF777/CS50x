#include <cs50.h>
#include <stdio.h>
#include <string.h> // strlen function works from this header

int main(void)
{
    string letters = get_string(" Enter letters: ");
    int length = strlen(letters);
    for (int i = 0; i < length -1 ;i++) // length -1 to stop at last char of letters, and not go further
    {
        // printf("%i ", letters[i]);
        //check if characters are in alphabetical order
        if (letters[i] < letters[i+1])
        {
            printf("%i ", i);
            printf("%c ", letters[i]);
            printf("%i ", letters[i]);
            printf("In order \n");
            // return 0; // this tells the program to quit
        }
        else
        {
            printf("%i ", i);
            printf("%c ", letters[i]);
            printf("%i ", letters[i]);
            printf("Not in order \n");
        }
    }
    //printf("Alphabetical order\n");
    //return 0;
}

