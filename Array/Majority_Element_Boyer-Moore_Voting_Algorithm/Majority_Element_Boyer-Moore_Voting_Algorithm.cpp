// Majority_Element_Boyer-Moore_Voting_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Problem Statement:
    We are trying to find the majority element in an array. The majority element is the element that appears more than n/2 times, where n is the length of the array.
    In this case, the array contains 15 elements, and the majority element is 5 because it appears 8 times, which is more than 15/2 = 7.5.


Steps in the Program: 

Step 1: Finding the Candidate
The Boyer-Moore Voting Algorithm is designed to identify a potential candidate for the majority element in a single pass through the array.

Initialize:

    count = 0 (This will keep track of how many times the current element appears in the array.)
    element is undefined initially. We'll set it as we go through the array.

Iterate through the array:

  For each element arr[i]:

    If count == 0: This means we haven't found a potential candidate yet, or the count for the previous candidate has become 0. 
    So, we update element to the current array element (arr[i]), and set count = 1.
    If arr[i] == element: This means the current element is the same as the candidate. We increment the count.
    If arr[i] != element: This means the current element is different from the candidate. We decrement the count.
*/

#include <iostream>
using namespace std;

int majority_element(int arr[], int n)
{
    int count = 0;
    int element;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
            count--;
    }
    int count_1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            count_1++;
    }

    if (count_1 > n / 2)
    {
        return element;
    }
    return -1;
}
int main()
{
    int arr[] = {7,7,5,7,5,1,5,7,5,7,7,5,5,5,5 }; // output - 5
  //  int arr[] = { 7,7,5,7,5,1,5,7,5,7,7,1,1,1,1 };   // output = -1 ... because it check the major if condition if (count_1 > n/2) also if it's yes then return element 
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = majority_element(arr, n);
    cout << "Most voting element is : " << result << endl;
    return 0;
}

/*

Dry Run : 

Look at the first loop with array - arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 7, 7, 5, 5, 5, 5}

Iteration 1 (i = 0):

    arr[0] = 7
    Since count == 0, set element = 7, count = 1.

Iteration 2 (i = 1):

    arr[1] = 7
    arr[1] == element (7 == 7), increment count = 2.

Iteration 3 (i = 2):

    arr[2] = 5
    arr[2] != element (5 != 7), decrement count = 1.

Iteration 4 (i = 3):

    arr[3] = 7
    arr[3] == element (7 == 7), increment count = 2.

Iteration 5 (i = 4):

    arr[4] = 5
    arr[4] != element (5 != 7), decrement count = 1.

Iteration 6 (i = 5):

    arr[5] = 1
    arr[5] != element (1 != 7), decrement count = 0.

Iteration 7 (i = 6):

    arr[6] = 5
    Since count == 0, set element = 5, count = 1.

Iteration 8 (i = 7):

    arr[7] = 7
    arr[7] != element (7 != 5), decrement count = 0.

Iteration 9 (i = 8):

    arr[8] = 5
    Since count == 0, set element = 5, count = 1.

Iteration 10 (i = 9):

    arr[9] = 7
    arr[9] != element (7 != 5), decrement count = 0.

Iteration 11 (i = 10):

    arr[10] = 7
    Since count == 0, set element = 7, count = 1.

Iteration 12 (i = 11):

    arr[11] = 5
    arr[11] != element (5 != 7), decrement count = 0.

Iteration 13 (i = 12):

    arr[12] = 5
    Since count == 0, set element = 5, count = 1.

Iteration 14 (i = 13):

    arr[13] = 5
    arr[13] == element (5 == 5), increment count = 2.

Iteration 15 (i = 14):

    arr[14] = 5
    arr[14] == element (5 == 5), increment count = 3.

After the first loop, element = 5 and count = 3.

Candidate Element: 5 is now the candidate.

-----------  Step 2: Verifying the Candidate -------------

Now, we verify if the candidate (element = 5) is actually the majority element by counting its occurrences in the array.
We need to check if the count of the candidate is more than n/2 (which is 15/2 = 7.5).

Second loop counts the occurrences of 5 in the array: 
    There are 8 occurrences of 5 in the array (positions 2, 4, 6, 8, 11, 12, 13, 14).
    Since count_1 = 8 is greater than n/2 = 7.5, we confirm that 5 is indeed the majority element.

---------- Final output - Most voting element is : 5 ---------

*/