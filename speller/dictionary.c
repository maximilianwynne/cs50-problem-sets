// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

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
const unsigned int N = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // hash word to obtain hash value
    int hash_value = hash(word);

    // access linked list/hash table
    node *n = table[hash_table]

    // traverse linked list, looking for word - strcasecomp
    while (n != NULL)
    {
        if (strcasecomp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int x = hash("apple")
    // add ascii values of each character in the word we are looking for to find the word
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        // use modulo to get a value within the hash table
        sum += tolower(word);
    }
    // adding up all ascii values in string and returning hash code modded by hash_max
    return sum % HASH_MAX
}

// Loads dictionary into memory, returning true if successful else false
// The purpose of this function is to take a dictionary file, which is the sole argument, open it, and add each word into the hash table at an appropriate index using the hash() function.
// The first step is to open the dictionary file using fopen() and assign it to a FILE variable, printing an error message if this does not work. A blank char array is then defined to store each word before it gets added to the hash table.
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");

    // check if null / the dictionary cannot be opened
    if (dictionary == NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }
    else
    {
        return true;
    }

    // define blank char array, store each word before added to hash table
    char next_word[LENGTH + 1];

    // read strings from file one at a time; make sure you are not at end of file
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // we then store each word in 'n' - memory allocated using malloc()
        node *n = malloc(sizeof(node));
        // if there is not enough memory
        if (n == NULL)
        {
            return false;
        }

        // copy word into node using strcopy
        strcpy(n->word, next_word);

        // get hash value for each word using hash() function
        int hash_value = hash(next_word);

        // insert node into hash table at that location
        n->table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    // close file
    fclose(dict_pointer || dictionary);
}

// return dictionary size - tracking number of words as they are loading under dict_size
unsigned int size(void)
{
    return dict_size;
}

void print()
{
    // count number of nodes within a linked list in hash table
    // temp pointer points to head
    struct node* temp = head;

    // initialise count variable
    int count=0;

    // traverse the linked list and maintain the count
    while(temp != NULL) {

        temp = temp->next;

        // increment count variable
        count++;

    }

    printf("\n Total no. of words in the dictionary", count);
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // assign cursor
        node *n = table[i];

        // loop through linked list inside hash table
        while (n != NULL)
        {
            // make temp equal censor;
            node *tmp = n;
            // point cursor to next element
            n = n->next;
            // free temp
            free(tmp);
        }


        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
}
