// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Get hash value for word
    int hash_value = hash(word);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }

    n = table[hash_value];

    // Check the first hash table if next is null
    if (n->next == NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }

        // There is no next more to check, so return false
        return false;
    }

    while(n->next != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int total = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        // Sum a total value
        total += len + toupper(word[i]);
    }

    // Get the value in range of N
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // While fscanf returning data
    while (fscanf(file, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);

        // Get hash
        int hash_value = hash(word);

        n->next = table[hash_value];

        table[hash_value] = n;

        wordcount++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
