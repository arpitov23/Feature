// Rearrange_array_with_alternating_positive_negative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void rearrange_array(int arr[], int n)
{

    int* pos = new int[n];
    int* neg = new int[n];

    int pos_index = 0;
    int neg_index = 0;

    // separate positive and negative numbers into 2 arrays

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos[pos_index++] = arr[i];
        else
            neg[neg_index++] = arr[i];
    }

    // Merge positive and negative numbers alternately 

    int i = 0, j = 0, k = 0;

    // place elements alternately

    while (i < pos_index && j < neg_index)
    {
        // First place a positive number then negative
        arr[k++] = pos[i++];   // first place positve number 
        arr[k++] = neg[j++];   // append negative number 

    }

    // if any positve nunmber are left append them
    while (i < pos_index)
    {
        arr[k++] = pos[i++];
    }

    // if any negative number are left append them
    while (j < neg_index)
    {
        arr[k++] = neg[j++];
    }
    

}
int main()
{
    int arr[] = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange_array(arr, n);

    // Print the rearranged array
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}



/*
   ------ Dry Run --------

Step-by-Step Dry Run:
Step 1: Initialize arrays

        arr[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}
        positive[] = {} (empty initially)
        negative[] = {} (empty initially)
        posIndex = 0 (index for positive array)
        negIndex = 0 (index for negative array)

Step 2: Separate positive and negative numbers
We loop through the original array and separate the positive and negative numbers into two arrays (positive[] and negative[]).

i = 0, arr[i] = 1 (positive)
Add 1 to positive[].
positive[] = {1}, posIndex = 1

        i = 1, arr[i] = -2 (negative)
        Add -2 to negative[].
        negative[] = {-2}, negIndex = 1

i = 2, arr[i] = 3 (positive)
Add 3 to positive[].
positive[] = {1, 3}, posIndex = 2

        i = 3, arr[i] = -4 (negative)
        Add -4 to negative[].
        negative[] = {-2, -4}, negIndex = 2

i = 4, arr[i] = 5 (positive)
Add 5 to positive[].
positive[] = {1, 3, 5}, posIndex = 3

        i = 5, arr[i] = -6 (negative)
        Add -6 to negative[].
        negative[] = {-2, -4, -6}, negIndex = 3

i = 6, arr[i] = 7 (positive)
Add 7 to positive[].
positive[] = {1, 3, 5, 7}, posIndex = 4

        i = 7, arr[i] = -8 (negative)
        Add -8 to negative[].
        negative[] = {-2, -4, -6, -8}, negIndex = 4

i = 8, arr[i] = 9 (positive)
Add 9 to positive[].
positive[] = {1, 3, 5, 7, 9}, posIndex = 5

        i = 9, arr[i] = -10 (negative)
        Add -10 to negative[].
        negative[] = {-2, -4, -6, -8, -10}, negIndex = 5

At the end of this loop:

        positive[] = {1, 3, 5, 7, 9}
        negative[] = {-2, -4, -6, -8, -10}

Step 3: Merge them alternately
We now merge the positive[] and negative[] arrays in alternating order.

We initialize:

    i = 0 (pointer for positive[])
    j = 0 (pointer for negative[])
    k = 0 (pointer for arr[])

Now, we'll place elements from positive[] and negative[] alternately into arr[].

i = 0, j = 0, arr[k] = positive[i] = 1
Place 1 at arr[0].
arr[] = {1, _, _, _, _, _, _, _, _, _}, k = 1, i = 1

        i = 1, j = 0, arr[k] = negative[j] = -2
        Place -2 at arr[1].
        arr[] = {1, -2, _, _, _, _, _, _, _, _}, k = 2, j = 1

i = 1, j = 1, arr[k] = positive[i] = 3
Place 3 at arr[2].
arr[] = {1, -2, 3, _, _, _, _, _, _, _}, k = 3, i = 2

        i = 2, j = 1, arr[k] = negative[j] = -4
        Place -4 at arr[3].
        arr[] = {1, -2, 3, -4, _, _, _, _, _, _}, k = 4, j = 2

i = 2, j = 2, arr[k] = positive[i] = 5
Place 5 at arr[4].
arr[] = {1, -2, 3, -4, 5, _, _, _, _, _}, k = 5, i = 3

        i = 3, j = 2, arr[k] = negative[j] = -6
        Place -6 at arr[5].
        arr[] = {1, -2, 3, -4, 5, -6, _, _, _, _}, k = 6, j = 3

i = 3, j = 3, arr[k] = positive[i] = 7
Place 7 at arr[6].
arr[] = {1, -2, 3, -4, 5, -6, 7, _, _, _}, k = 7, i = 4

        i = 4, j = 3, arr[k] = negative[j] = -8
        Place -8 at arr[7].
        arr[] = {1, -2, 3, -4, 5, -6, 7, -8, _, _}, k = 8, j = 4

i = 4, j = 4, arr[k] = positive[i] = 9
Place 9 at arr[8].
arr[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, _}, k = 9, i = 5

        i = 5, j = 4, arr[k] = negative[j] = -10
        Place -10 at arr[9].
        arr[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}, k = 10, j = 5

Now, all elements have been placed alternately.

Final - arr[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}




*/