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

    // run through the data through hash
    int x = hash("apple");
    // x is now hash
    hashtable[x] = "apple";

    // djib2 (Dan Bernstein) hash function
    unsigned int hash(const char *word)
    {
	    unsigned long hash = 5381;
	    int c = *word;
	    // tolower - change every letter to be lowercase (to make sure words like 'And' and 'and' give the same hash result)
	    c = tolower(c);
	    while (*word != 0)

    {
	    hash = ((hash << 5) + hash) + c;
	    c = *word++;
	    c = tolower(c);
    }
    // change the return value to fit the size of hash table (N)
    return hash % N;
};

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Iterate over every linked list inside of the hash table
    void* data;
    struct list_node* next;
};

    struct list {
    struct list_node* head;
};

    struct list* list_create() {
        struct list* l = malloc(sizeof(struct list));
        l->head = NULL;
        return l;
};

    size_t list_size(struct list* l) {
        size_t size = 0;
        struct list_node* curr = l->head;
        while (curr) {
            size++;
            curr = curr->next;
    }
    return size;
};

    void list_free(struct list* l, bool free_data) {
        struct list_node* curr = l->head;
        struct list_node* next;
        while (curr) {
            next = curr->next;
            if (free_data) {
                free(curr->data);
            }
            free(curr);
            curr = next;
    }
    free(l);
}

void print(){

    // count number of nodes within a linked list in hash table
    // temp pointer points to head
    struct node* temp = head;

    // initialise count variable
    int count=0;

    // traverse the linked list and maintain the count
    while(temp != NULL){

        temp = temp->next;

        // increment count variable
        count++;

    }

    printf("\n Total no. of words in the dictionary",count);

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
