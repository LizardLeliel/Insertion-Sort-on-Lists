#include "simple_insertion.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// Declaration in simple_insertion.h
typedef struct list_node 
{
    struct list_node* next;
    struct list_node* back;
    unsigned int value;
} list_node_t;


list_t* create_list()
{
    list_t* newList = malloc(sizeof(list_t));

    newList->top    = NULL;
    newList->length = 0; // We actually don't need this, do we?

    return newList;
}


void delete_list(list_t* list)
{
    // Delete all of them soon
    list_node_t* chaser = list->top;
    list_node_t* temporary_node;

    while (chaser != NULL)
    {
        temporary_node = chaser;
        chaser = chaser->next;
        free(temporary_node);
    }
    

    free(list);
}


void list_insert(list_t* list, unsigned int value)
{
    list_node_t* newNode = malloc(sizeof(list_node_t));

    // Insert at top
    newNode->value  = value;
    newNode->back   = NULL;    
    newNode->next   = list->top;
    list->top       = newNode;

    if (list->top->next != NULL)
    {
        list->top->next->back = list->top;
    }

}


// Helper Function for the function below
void put_into_place(
    list_node_t* toBeSorted, 
    list_node_t* alreadySorted,
    unsigned int* assignments,
    unsigned int* comparisons
)
{
    // I'm not counting null comparisons as a comparison;
    //  After all, seeing if a for loop has ended isn't counted
    //  as a comparison in an array implementation
    // Note that I put the comparison increment in the while loop
    //  so will count the value being compared, but won't count if
    //  if short circuiting occurs, but will occur if the comparison
    //  returns false.
    // ++x returns x + 1, and since x is only zero or greated, it will
    //  always resolve to true.
    while (alreadySorted != NULL &&
           ++(*comparisons)      &&
           alreadySorted->value > toBeSorted->value
    ) 
    {
        // It is clearer to group the assignments
        ++(*assignments);
        ++(*assignments);
        ++(*assignments);
        unsigned int temp    = toBeSorted->value;
        toBeSorted->value    = alreadySorted->value;
        alreadySorted->value = temp;

        ++(*assignments);
        ++(*assignments);
        alreadySorted = alreadySorted->back;
        toBeSorted    = toBeSorted->back;
    }

}


results_t list_insertion_sort(list_t* list)
{
    unsigned int assignments = 0;
    unsigned int comparisons = 0;

    if (list->top != NULL)
    {
        ++assignments;
        ++assignments;
        list_node_t* toBeSorted    = list->top->next;
        list_node_t* alreadySorted = list->top;
        
        while (toBeSorted != NULL)
        {
            put_into_place(toBeSorted, 
                alreadySorted, 
                &assignments, 
                &comparisons
            );
            
            toBeSorted    = toBeSorted->next;
            alreadySorted = alreadySorted->next;
        }
    }

    results_t results;
    results.assignments = assignments;
    results.comparisons = comparisons;
    return results;
}


// Returns false if value was not found in the list,
//  and therefore was not removed
bool list_remove(list_t* list, unsigned int value)
{
    return false;
}


void print_whole_list(list_t* list)
{
    list_node_t* chaser = list->top;
    unsigned int depth = 0;
    while (chaser != NULL)
    {
        ++depth;
        printf("%u: %u\n", depth, chaser->value);
        chaser = chaser->next;
    }
}