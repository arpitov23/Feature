// Remove_Duplicate_From_Undorted_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
using namespace std; 

void remove_dup_unsorted_array(int arr[], int size)
{
    unordered_set<int> seen; //hash set to tract seen element
    bool dup_found = false;

    // traverse through the array
    for (int i = 0; i < size; i++)
    {
        // if the element is already in the set, it's a duplicate
        if (seen.find(arr[i]) != seen.end())
        {
            cout << "Duplicate element found : " << arr[i] << endl;
            dup_found = true;
        }
        else
        {
            //add the element to the set if not already present 
            seen.insert(arr[i]);
        }
    }
    if (!dup_found)
        cout << "No duplicate found!" << endl;
}
int main()
{
    int arr[] = { 4, 2, 3, 4, 5, 6, 2, 0, 9 ,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    remove_dup_unsorted_array(arr, size);

    return 0;
}

/*

Approach - 
We use an unordered set (unordered_set<int>) to keep track of the elements we encounter as we traverse the array.
If we encounter an element that is already in the set, it is a duplicate.
If not, we add the element to the set.
This method has a time complexity of 𝑂(𝑛)  and a space complexity of O(n).

*/


// ------------------- Second Approach - Sort the array then compare -----------------

/*
#include <iostream>
#include <algorithm>
using namespace std;

void findDuplicate(int arr[], int size) {
    // Sort the array
    sort(arr, arr + size);

    bool foundDuplicate = false;

    // Check adjacent elements in the sorted array
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            cout << "Duplicate element found: " << arr[i] << endl;
            foundDuplicate = true;
        }
    }

    if (!foundDuplicate) {
        cout << "No duplicates found!" << endl;
    }
}

int main() {
    int arr[] = {4, 2, 3, 4, 5, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicate(arr, size);

    return 0;
}

*/

/*
  Compare between Hash_Set and Sorting Approach 

Using Hash Set:

    Time Complexity: O(n)
    Space Complexity: O(n)
    Efficient but uses extra space (hash set).

Using Sorting:

    Time Complexity:O(nlogn) (due to sorting)
    Space Complexity:O(1) (if sorting in place)
    Good for cases when you want to modify the array.
*/