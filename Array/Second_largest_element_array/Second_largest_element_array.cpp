// Second_largest_element_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int second_lar(int arr[], int n)
{
    if (n < 2) {
        cout << "array should have at least 2 elements\n";
        return INT_MIN;
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;

}


int main()
{
    int arr[] = { 12,35,1,10,34,1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int secondLargest = second_lar(arr, n);

    if (secondLargest != INT_MIN) {
        cout << "The second largest element is: " << secondLargest << endl;
    }
    else {
        cout << "Second largest element not found." << endl;
    }

    return 0;
}

