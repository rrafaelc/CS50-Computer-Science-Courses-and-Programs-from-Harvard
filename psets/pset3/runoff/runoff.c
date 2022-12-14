#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
}
candidate;

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
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
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

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Query all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Find the candidate name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // [0][0] = 2
            // [Joe][rank1] = Charlie
            preferences[voter][rank] = i;

            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Query voters
    for (int i = 0; i < voter_count; i++)
    {
        bool compute_vote = true;

        // Query the candidates
        for (int j = 0; j < candidate_count; j++)
        {
            // Get candidate index
            int candidate = preferences[i][j];

            // If is eliminated go to next candidate
            if (candidates[candidate].eliminated)
            {
                // If the current candidate is eliminated, don't let vote
                compute_vote = false;
            }
            else
            {
                // If not, compute the vote
                compute_vote = true;
            }

            // Add one vote to the candidate if compute_vote is true
            if (compute_vote)
            {
                candidates[candidate].votes++;

                //Break the for loop
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Condition to win is half vote plus 1
    int condition = voter_count / 2 + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        // Find the candidate that matches the condition
        if (candidates[i].votes == condition)
        {
            // printf("%s is the winner\n", candidates[i].name);
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min;

    for (int i = 0; i < candidate_count; i++)
    {
        // Only if the candidate is not eliminated
        if (!candidates[i].eliminated)
        {
            // If the candidate votes is small than the min
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }

    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Only if the candidate is not eliminated
        if (!candidates[i].eliminated)
        {
            // If one candidate is different from min, so it's not tie
            if (candidates[i].votes > min)
            {
                return false;
            }
        }
    }

    // If no candidate is higher than min, than is tie
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Query the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If wasn't already eliminated
        if (!candidates[i].eliminated)
        {
            // If the candidate matches the min
            if (candidates[i].votes == min)
            {
                // Set eliminated to true
                candidates[i].eliminated = true;
            }
        }
    }

    return;
}