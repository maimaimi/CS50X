// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int countWord = 0;

node *table[N]; // Hash table

bool check(const char *word) // Returns true if word is in dictionary, else false
{
    // TODO
    int hash_Number = hash(word);
    node *cursor = table[hash_Number];

    while (cursor != NULL)   //loop until the end of linked list
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;     //otherwise move to the next node
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO - open the dictionary file - Read

    FILE *Dictionary_file = fopen(dictionary, "r");
    if (Dictionary_file == NULL)
    {
        return false;
    }
    char str[LENGTH + 1];
    while (fscanf(Dictionary_file, "%s", str) != EOF)    // fscanf will return EOF(end of file) once it reaches end of file
    {
        node *temp = malloc(sizeof(node));      //a new node. in order to allocate memory for a new node.
        if (temp == NULL)
        {
            return false;
        }
        strcpy(temp->word, str); //copy word into node
        int hash_Number = hash(str);

        if (table[hash_Number] == NULL)
        {
            temp->next = NULL; //point temp to NULL
        }
        else //access AHEAD
        {
            temp->next = table[hash_Number]; //going to point temp
        }
        table[hash_Number] = temp;

        countWord += 1;
    }
    fclose(Dictionary_file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return countWord;
}
void freenode(node *n)
{
    if (n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}


