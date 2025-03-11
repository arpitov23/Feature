// Majority_Element_in_an_Array (Boyer-Moore Voting Algorithm).cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem: Find the element that appears more than ⌊n / 2⌋ times in the array.


// This algorithm works on the fact that if an element occurs more than N/2 times, it means that the remaining elements other than this would definitely be less than N/2


// Approach - First, choose a candidate from the given set of elements if it is the same as the candidate element, increase the votes.
//  Otherwise, decrease the votes if votes become 0, select another new element as the new candidate.

#include <iostream>
using namespace std;

// first find out the candidate with majority elemnent

int findMajorityelement(int arr[], int size)
{
    int candidate = arr[0];
    int count = 1;

    // phase 1 : find the candidate

    for (int i = 1; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            candidate = arr[i];
            count = 1; 
        }
    }

    // phase 2: verify if the candidate is actually the majority element 

    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > size / 2)
    {
        return candidate;
    }
    else
    {
        return -1; // No majority element
    }
}

int main()
{
    int arr[] = { -10, 2, 3, -10, -10, 4, -10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findMajorityelement(arr, size);
    if (result != -1)
        cout << "Majority element: " << result << endl;
    else
        cout << "No Majority element" << endl;
    return 0;
}

