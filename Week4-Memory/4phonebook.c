// Making a phonebook .csv file
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open phonebook.csv file, with pointer to next memory block of it
    FILE *file = fopen("phonebook.csv", "a"); // file is the pointer area
    if (!file) // Check for NULL
    {
        return 1;
    }
    //Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    // Print to file
    fprintf(file, "%s,%s\n", name, number);
    // Close file
    fclose(file);
}
