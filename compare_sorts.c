#include "compare_sorts.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "simple_insertion.h"

void print_results(results_t results, 
    unsigned int listSize, 
    unsigned int arraysPerSize
)
{
    printf("Average # of assignments and comparisons across %u list(s) of size %u:\n",
        arraysPerSize,
        listSize);
    printf("%u, %u\n", results.assignments, results.comparisons);
}

void compare_sorts(
    size_t initialSize,
    unsigned int arraysPerSize,
    unsigned int maxIterations
) 
{
    // Keep getting bigger data
    unsigned int currentListSize = initialSize;
    for (int i = 0; i < maxIterations; ++i)
    {
        results_t averageResults;
        averageResults.assignments = 0;
        averageResults.comparisons = 0;

        // Get the average for x ammount of n sized arrays
        for (int j = 0; j < arraysPerSize; ++j)
        {
            results_t results;
            results.assignments = 0;
            results.comparisons = 0;

            list_t* list = create_list();

            // Fill the array
            for (int k = 0; k < currentListSize; ++k)
            {
                list_insert(list, rand());
            }

            results = list_insertion_sort(list);
            delete_list(list);

            // This will lead to overflow eventually.
            averageResults.assignments += results.assignments;
            averageResults.comparisons += results.comparisons;
        }


        averageResults.assignments /= arraysPerSize;
        averageResults.comparisons /= arraysPerSize; 

        // Print the average of this size
        print_results(averageResults, currentListSize, arraysPerSize);
        currentListSize *= 2;
    }
}

void example_list_sort()
{
    srand(time(NULL));

    // Of size 100
    list_t* list = create_list();

    for (int i = 0; i < 50; ++i)
    {
        list_insert(list, rand());
    }

    puts("Before Sorting:");
    print_whole_list(list);

    results_t result = list_insertion_sort(list);

    puts("After Sorting:");
    print_whole_list(list);

    delete_list(list);
}

