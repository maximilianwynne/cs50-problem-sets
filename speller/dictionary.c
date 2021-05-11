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

    // access linked list/hash table
    node *n = table[hash_table]

    // traverse linked list, looking for word 'apple'
    while (n != NULL)
    {
        if (apple(word, n->word) == 0)
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
    // add ascii values of each character in the word we are looking for to find the word
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        // use modulo to get a value within the hash table
        sum % N += tolower(word);
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
	    // tolower - change every letter to be lowercase (to make sure words give the same hash result)
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
};

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
    // free all nodes in linked list within hash table
    void free_hashtable(void);

    if (hashtable != 0)
    {
        for (int i = 0; i < tsize; i++)
        {
            hash_ptr next = 0;
            for (hash_ptr curr = htable[i]; curr != 0; curr = next)
            {
                next = curr->next;
                free(curr->word);
                free(curr);
            }
        }
        free(htable);
        htable = 0;
        tsize = 0;
    }
}
else {
    // if successful in unloading and reading hashtable, read false
    return false;
}
