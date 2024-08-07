#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    // Keep querying for votes
    for (int i = 0; i < voter_count; i++) // outer loop pacing through voters 1x1 in preference[i]
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++) // inner loop pacing through each rank in preference[][j]
        {
            string name = get_string("Rank %i: ", j + 1); // Rank 1: , then Rank 2: etc
            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < voter_count; i++) // outer loop for voters
    {
        printf("Voter %i:", i);
        for (int j = 0; j < candidate_count; j++) // inner loop printing ranks
        {
                printf("Rank %i = ",j);
                printf("%i ",preferences[i][j]);
        }
        printf("\n");
    }
    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();
         // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);
        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        //Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    printf("\n");
    return 0;
}
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++) // Iterate over each candidate
    {
        if (strcmp(candidates[i].name, name) == 0) // strcmp returns 0 when the same
        {
            // Check if candidate's name matches given name.
            // If yes, add ranking to its place in preference[i][j]
            preferences[voter][rank] = i ;
            return true;
        }
    }
    return false;
}
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //calculate votes
    for (int i = 0; i < voter_count; i++) // outer loop for voters
    {
        for (int j = 0; j < candidate_count; j++) // outer loop for ranks
        {
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}
// Print the winner of the election, if there is one
bool print_winner(void)
{
    float winvotes;
    if (voter_count % 2 == 0) // if vote_count is 6 winvote must be 4
    {
        winvotes = 1 + ceil((float)voter_count/2);
    }
    else // if vote_count is 7 winvote must remain 4
    {
        winvotes = ceil((float)voter_count/2);
    }

    printf ("whoever has %i votes, or more, wins!\n", (int)winvotes);
    for (int j = 0; j < candidate_count; j++)
    {
        printf ("%s: has %i votes. ", candidates[j].name, candidates[j].votes);
    }
    for (int j = 0; j < candidate_count; j++) // loop through candidates
    {
        if (candidates[j].votes >= (int)winvotes)
        {
            printf ("\n%s wins!!!!", candidates[j].name);
            return true;
        }
        else
        {
            printf ("\nNo winner yet");
        }
    }
    return false;
}
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minvotes = voter_count*candidate_count;
    for (int j = 0; j < candidate_count; j++) // loop through candidates
    {
        if (!candidates[j].eliminated) // only running candidates are included
        {
            if (candidates[j].votes < minvotes)
            {
                minvotes = candidates[j].votes;
            }
        }
    }
    printf ("\nMinimum votes = %i ", minvotes);
    return minvotes;
}
// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int maxvotes = 0;
    for (int j = 0; j < candidate_count; j++) // loop through candidates
    {
        if (!candidates[j].eliminated) // only running candidates are included
        {
            if (candidates[j].votes > maxvotes)
            {
                maxvotes = candidates[j].votes;
            }
        }
    }
    printf ("\nMaximum votes = %i ", maxvotes);
    if (min  == maxvotes)
    {
        return true;
    }
    return false;
}
// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int j = 0; j < candidate_count; j++) // loop through candidates
    {
        if (!candidates[j].eliminated) // only running candidates are included
        {
            if (candidates[j].votes == min)
            {
                candidates[j].eliminated = true;
                printf ("\nCandidate %s with %i votes has been eliminated.", candidates[j].name, candidates[j].votes);
            }
        }
    }
    return;
}
