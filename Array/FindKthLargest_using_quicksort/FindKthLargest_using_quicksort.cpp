// FindKthLargest_using_quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // using last element as pivot
    int i = low - 1;

    // Rearranging in a such a way that element greater than pivot are on left side
    // and less than or equal to right end side 

    for (int j = low; j < high; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
   
    return i+1;   // indexing value - if you give i then only 3rd value will be printed i.e. 5 if you give i+1 then print 7 because array invoke based on indexing  

}

// QuickSelect function to find the kth largest element 

int quickselect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high); // partition index

        // if the partition index is the kth largest element 
        if (pi == k - 1)
        {
            return arr[pi];
        }
        // if the kth largest element is in left partition
        else if (pi > k - 1)
        {
            return quickselect(arr, low, pi - 1, k);
        }
        // if the kth largest element in in right partition
        else
        {
            return quickselect(arr, pi + 1, high, k);
        }
    }
    return -1; // This case should not occur if k is valid
}





int main()
{
    int arr[] = { 12,3,5,7,19,2 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 
    cout << "kth element is : "<< quickselect(arr, 0, size - 1, k);

    return 0;
}
