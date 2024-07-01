#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote using vote function
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
            printf ("i = %i \n", i);

    }

            printf ("now going to print winner\n");


    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // strcmp returns 0 when the same
        {
        // Check if candidate's name matches given name
        // If yes, increment candidates vote and return true
            candidates[i].votes += 1;
            printf ("%s: ", candidates[i].name);
            printf ("has %i votes. ", candidates[i].votes);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Find the max number of votes
    int maxvotes = 0;
    printf (" in print winner\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf ("i = %i & ", i);
        // Check for maximum votes
        if (candidates[i].votes > maxvotes)
        {
            // If yes, maxvotes must get higher value
            maxvotes = candidates[i].votes;
            printf("maxvotes is now: %i\n", maxvotes);
        }
    }

    // Print the candidate (or candidates) with maximum votes
    for (int i = 0; i < candidate_count; i++)
    {
        // Check maxvotes to print candidate
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }

    }

}
