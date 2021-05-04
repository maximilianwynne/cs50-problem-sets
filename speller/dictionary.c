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
    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    // add a variable to the end of the list
    node_t *head = NULL;
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
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    typedef struct {
        char *key;
        int value;
    } item;

    item* linear_search(item* items, size_t size, const char* key) {
        for (size_t i=0; i < size; i++) {
            if (strcmp(items[i].key, key) == 0) {
                return &items[i];
            }
        }
        return NULL;
    }

    int main(void) {
        item items[] = {
            {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
            {"apple", 11}, {"jane", 100}, {"x", 200}};
        size_t num_items = sizeof(items) / sizeof(item);

        item* found = linear_search(items, num_items, "apple");
        if (!found) {
            return 1;
        }
        printf("linear_search: value of 'apple' is %d\n", found->value);
        return 0;
    }
}
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    }
    node;

    const int N = 300;
    node *table[N];

    // allocate memory for new node
    node *n = malloc(sizeof(node));
    strcpy(n->word, "apple");
    n->next = NULL;

    // find file size
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    rewind(f);

    // read characters from file and return EOF at end of file
    FILE *fp
    char buff[300]
    fp = fopen("bible.txt", "r");
    while(fscanf(fp, "%s", buff)!=EOF){

        printf("%s ", buff );
    }
    fclose(fp);
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
