#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // if (strings[i] == s) needs strcmp from string.h to be able to campare strings
        if (strcmp(strings[i], s) == 0) // strcmp evaluates the 2 args, if the same, it returns 0
        // strcmp also checks ASCIIbetical order and then returns
        //an int less than 0 if strings[i] comes before s,
        //0 if string[i] is the same as s,
        //an int greater than 0 if strings[i] comes after s.
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
