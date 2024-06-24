// Week3-Section manual structured presidential candidates with votes
// Checking who got the most votes

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// struct = data structure = creates a data "type" which holds a collection of other basic types.
typedef struct //(Define the following type)used to keep info of individual thing or person together
{
    string name; // structure members of the candidate
    int votes;
}
// struct candidate is a template of structural members
candidate; // typedef defines a new data-type with name 'candidate' to be re-used

int main(void)
{
    const int numcan = 4;
    //type_name variable_name[array_size]
    candidate president[numcan]; // declare array of presidential candidates
// create an array of candidates
    president[0].name = "ben";
    president[0].votes = 10;
    president[1].name = "piet";
    president[1].votes = 6;
    president[2].name = "koos";
    president[2].votes = 7;
    president[3].name = "jan";
    president[3].votes = 9;

// Search the array for most votes awarded & then who has it
    int maxvotes = 0;
    for (int i = 0; i < numcan; i++)
    // First have to establish highest number of votes
    {
        if (president[i].votes > maxvotes)
        {
            maxvotes = president[i].votes;
            printf("Maxvotes %i\n", maxvotes);
        }
    }
// Find candidate with same votes as maxvotes then print out that candidate's name.
    for (int i = 0; i < numcan; i++)
    {
        if (president[i].votes == maxvotes)
        {
            printf("Presidential candidate %s has ", president[i].name);
            printf("%i votes.\n", president[i].votes);
        }
    }

}
