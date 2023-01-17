#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

int get_int(string prompt) {
    char buffer[100];
    printf(prompt);
    fgets(buffer, 100, stdin);

    return strtol(buffer, NULL, 0);;
}

string get_string(string prompt) {
    printf(prompt);
    char input[100];
    fgets(input, 100, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    char* result = (char*) malloc(sizeof(char)*(len+1));
    strcpy(result, input);
    return result;
}

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    printf("%d\n", argc);
    printf("[%s]\n", argv[1]);
    printf("[%s]\n", argv[2]);
    printf("[%s]\n", argv[3]);
    printf("[%s]\n", argv[4]);
    printf("[%s]\n", argv[5]);
    printf("#######\n");
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

    long long voter_count = get_int("Number of voters: ");

    printf("%d\n", voter_count);

    string name;
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        name = get_string("\nVote For: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Vote Is Invalid/Null\n");
        }
    }

    // Display winner of election
    printf("about to call\n");
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //
    printf("checking: %s\n", name);
    // access candidates list
    for (int i = 0; i < candidate_count; i++)
    {
        //printf("comparing %s and %s\n", candidates[i].name, name);
        //printf("[%s], [%s] result %d\n", candidates[i].name, name, strcmp(candidates[i].name, name) );
        if (strcmp(candidates[i].name, name) == 0)
        {
            //if candidates[i].name = candidates[i].votes, ++candidates[i].votes;
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_so_far = 0;
    char *name;
    int votes;
    string winners[100];
    int str_pointer = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        name = candidates[i].name;
        votes = candidates[i].votes;
        printf("%s recieved %d votes\n", name, votes);

        if (votes > max_so_far) {
            max_so_far = votes;
            winners[0] = name;
            str_pointer = 1;
        }
        else if (votes == max_so_far) {
            winners[str_pointer] = name;
            str_pointer++;
        }
        //printf("comparing %s and %s\n", candidates[i].name, name);

    }

    // winners {obama, trump, .....}

    int ptr = 0;
    while (ptr < str_pointer) {
        printf("%s, ", winners[ptr]);
        ptr++;
    }
    printf("wins!");
}
