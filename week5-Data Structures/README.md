# Speller: A guide to the ‘Speller’ problem in CS50 Week 5.

## Goal 
To implement a spell checker program in C. 
The program is partially written, but we must write functions that both load and unload the dictionary into memory, as well as checking if each word in the given text is in the dictionary and thus spelled correctly.
The dictionary should be loaded into a hash table, which can be looked up when checking if each word is spelt correctly. The aim is to minimise this lookup time by using an appropriate hash function.

## Step
use this function
- load
- hash
- size
- check
- unload 

> responsible for taking the dictionary and loading it into a hash table
> **Hash Table:** array of linked listsHash function: assigns a number to every input. 
               (Takes a word as input. Output a number corresponding to which "bucket" to store the word in)
```
bool load  (const char *dictionary)
{
// TO DO (true or false)
}
```
**Linked Lists:** Every node has a value, and a pointer to the next node. 
```
typedef struct node {
char word[LENGTH + 1];
struct node *next:
}
node;
```
```
const int N = 1;
node *table[N];
```
> then put some data into that node. in order to allocate memory for a new node. Ask for some memory from the computer
```
node *n = malloc(sizeof(node));
```

How do we put data into the node?
```
strcpy(n->word, "Hello");
n->next = NULL;
```

**TODO:**
- open dictionary file (use fopen. Remember to check if return value is NULL)
- Read strings from file one at a time (fscanf(file, "%s", word) fscan will return EOF(end of file) once it reaches end of file)
- Create a new node for each word (use malloc. Remember to check if return value is NULL. Copy word into node using strcpy)
- Hash word to obtain a hash value (use the hash function. Function takes a string and returns an index)
- insert node into hash table at that location (Recall that hash table is an array of linked lists. Be sure to set pointers in the correct order!)

hush function:
```
unsigned int hash(const char *word)
{
// TODO
- input: word, with alphabetical characters and apostrophes.
- output: numerical index between 0 and N - 1, inclusive
- deterministic
}
```
> Example Hash Function
- First letter
- First two letters
- Math using all the letters

> if the first letter of the word is Z, the hash value might be 25. in this case our value of N is 26 because we would have 26 different buckets, one for every letter of the alphabet. 


**size function & check function:**
- return true if the word is in the dictionary, false otherwise, 
- case insensitive
 
**TODO:**
- Hash word to obtain a hash value
- Access linked list at that index in the hash table
- Traverse linked list, looking for the word(strcasecmp) 
```
bool check(const char *word) 
{
TODO
}
```
> Traversing Linked List
- Start with cursor set to first time in linked list
- Keep moving cursor until you get to NULL, checking each node for the word. 
```
unload:
bool unload (void)
{
TODO
}
```
