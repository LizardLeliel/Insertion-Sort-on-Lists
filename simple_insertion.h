#ifndef SIMPLE_INSERTION
#define SIMPLE_INSERTION

#include <stdlib.h>
#include <stdbool.h>

struct list_node;

// Two way tree.
// I typedef it as list_t as this is what users will be using,
//  even though its just a wrapper.
typedef struct list_wrapper 
{
    struct list_node* top;
    size_t length;
} list_t; 

typedef struct results
{
    unsigned int assignments;
    unsigned int comparisons;

} results_t;

// List creation and deletion
list_t* create_list();
void    delete_list(list_t* list); // Can delete full or empty list

// Interface
void      list_insert(list_t* list, unsigned int value);
results_t list_insertion_sort(list_t* list);
bool      list_remove(list_t* list, unsigned int value);


// printing function
void print_whole_list(list_t* list);

// SIMPLE_INSERTION
#endif