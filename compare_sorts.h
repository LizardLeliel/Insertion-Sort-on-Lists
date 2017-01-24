#ifndef COMPARE_SORTS
#define COMPARE_SORTS

#include <stdlib.h>

// List size
// Random Variation Repeated Attempts
// (Time only) Same Array Repeated Attempts

// Parameters:
// - initialSize: how large the first array will be
// - listsPerIteration: how many different random arrays will be tested on
//    on any given sise (the average of swaps and comparisons will be given)
// - maxIterations: how many times you want to increase the size
// The Array doubles in size every iteration.
// The function will automatically end when the size of the list becomes
//  larger then can be represented in size_t
// This function also does all printing of results.
void compare_sorts(
    size_t initialSize,
    unsigned int listsPerSize,
    unsigned int maxIterations

);

void example_list_sort();


// COMPARE_SORTS
#endif