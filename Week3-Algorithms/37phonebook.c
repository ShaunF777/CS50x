#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David", "John"}; // codesmell because this related info should be stored better in like a structure
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"}; // best use strings if no arithmetic will be used

    string name = get_string("String: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]); // returns the persons number if found
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
