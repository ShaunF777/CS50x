#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    //instead of this  - string names[] = {"Carter", "David", "John"};
    // and this  - string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};
    // make 3 index array called people, using datatype person
    person people[3];
    // initialise those people
    people[0].name = "Carter";
    people[0].number = "613461367+++";
    // initialise those people
    people[1].name = "David";
    people[1].number ="777713461367+++";
    // initialise those people
    people[2].name = "John";
    people[2].number = "88883461367+++";

    string name = get_string("String: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number); // returns the persons number if found
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
