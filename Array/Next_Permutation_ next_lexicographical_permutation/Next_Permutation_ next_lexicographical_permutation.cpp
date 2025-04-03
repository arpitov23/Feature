// Next_Permutation_ next_lexicographical_permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Next Permutation Problem -

    Permutation - It means all possible combination 
    Next Permutation means - Find next lexicographical permutation of a sequence of numbers. 
    lexicographical means arrange in ascending order like dictionary

    Approach - 

    Brute-Force - generate all possible combination in sorted order 
                  linear search
                  Next index permutation and if it's the last one then first one will be your answer (reverse it)
               Time complexity - N! * N (huge )
    Better - Use STL library - next_permutation() - in-built function
    Optimal - below problem 

    Approach - 
    
        -> Longest Prefix match and find the break-point 
              a[i] < a[i+1];
        
        -> find index which is > break-point element, but the smallest one so that you stay close.

        -> Try to place remaining element in sorted order or simply reverse the remaining element or subarray.

    Algorithm - 

    step 1 -

    for (int i= n-2 ; i>= 0 ;i--)
    {
        if (a[i] > a[i+1])
        {
            ind = i;
            break ;
        }
    }

    step 2 - 

    for (int i= n-2 ; i>= 0 ;i--)
    {
        if (a[i] > a[ind])
        {
            swap(rr[i], arr[ind])
            break ;
        }
    }


    step 3 - 

    reverse (arr + ind+1, n-1) // till the last index
*/

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector <int> next_permutation(vector<int>&A)
{
    int index = -1;
    int n = A.size();

    for (int i = n - 2; i >= 0; i--)
    {

        //step 1: longest prefix match and finding the breaking point - 
        // Breaking Point  - For breaking point we are checking from the last - if any element is greater than their right side then that index is the breaking point.
        // or
        // Find the largest index suxh that A[i] < A[i+1]

        if (A[i] < A[i + 1])
        {
            index = i;
            break;
        }
    }
     
    // if there is no dip or last index is there then simply reverse - Ex - (3,2,1) then output will be  (1,2,3) - just reverse it/ 
    // or
    // If no such index exists, the array is in descending order, reverse it.

    if (index == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    
    // Step 2: find someone > 1 , but the smallest one so that you stay close. - After step 1st then simply check the next greater element after break point element .
    // Here in this case break point element is 1. So we are checking next greater element after 1 i.e. 3 . Once we got then simply swap 1 with 3.
    // or 
    // Find the largest index such that A[i] > A[index]

    for (int i = n-1; i > index; i-- )
    {

        // find greater and then just swap it
        if (A[i] > A[index])
        {
            swap(A[i], A[index]);
            break;
        }
    }

    // Step 3: for remaining element just reverse
    // or
    // Reverse the subarray from index+1 to end

    reverse(A.begin()+ index + 1, A.end());
    return A;

}

int main()
{
    vector<int> vec = {2,1,5,4,3,0,0 };
    
    vector <int> k = next_permutation(vec);

    for (auto i : k)
        cout << "next permutation order is: " << i << endl;
   

    return 0;
}

/*

Time Complexity - O(3N) - 1N (for loop) + 1N(second for loop) + 1N(remaining reverse element subarray)
Space complexity - O(1) - Not using any extra vector

*/