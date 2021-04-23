// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define MAX_WORD_LEN 50
char** dic[MAX_WORD_LEN];

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // hash word to obtain hash value
    int hash_value = hash(word);

    // access linked list at that index in hash table
    typedef struct node {

        int val;
        struct node* = table[hash_value];

    } node_t;

    // use the nodes - create local variable which points to the first item of the list (e.g., head)
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    // add a variable to the end of the list
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;

    // traverse the linked list
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
            n = n->next;
        }
    }

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
