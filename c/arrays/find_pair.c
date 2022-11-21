/*
    Author: Szymon Kublin
    Date: 2022-11-21
    Description: Find a pari with the given sum in an array.
*/

#include <stdio.h>
#include <stdlib.h>

void find_pair_naive(int array[], int length, int target)
{
    /*
        This method shows simple approach (Brute-Force) - just check each pair.
        
        Time complexity: O(n^2).
    */
    unsigned int counter = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] + array[j] == target)
            {
                printf("Found : %d + %d = %d\n", array[i], array[j], target);
                counter++;
            }
        }
    }

    if (counter == 0)
        printf("Not found!\n");
}

int comparison(const void * element_1, const void * element_2)
{
    /*
        Comparison function for qsort().
    */
    int f = *((int*)element_1);
    int s = *((int*)element_2);

    if (f > s) return 1;
    if (f < s) return -1;
    
    return 0;
}

void find_pair_sorting(int array[], int length, int target)
{
    /*
        This method shows better approach with sorting. 
        First, sort an array, then maintain two indices (low and high - initially endpoints) and use them to find pair.

        Time complexity: O(n*log(n)).
    */

    qsort(array, length, sizeof(*array), comparison);

    int low = 0;
    int high = length - 1;

    unsigned int counter = 0;

    while (low < high)
    {
        int current_sum = array[low] + array[high];

        if (current_sum == target)
        {
            printf("Found : %d + %d = %d\n", array[low], array[high], target);
            counter++;
            low++;
            high--;
        }

        if (current_sum < target)
            low++;
        else if (current_sum > target)
            high--;
    }

    if (counter == 0)
        printf("Not found!\n");
}

int main()
{
    int array[] = {15, 7, 11, 6, 23, 18, 16, 1};

    int length = sizeof(array) / sizeof(array[0]);

    int target = 17;

    printf("Naive method: \n");
    find_pair_naive(array, length, target);

    printf("Sorting method: \n");
    find_pair_sorting(array, length, target);

    return 0;
}