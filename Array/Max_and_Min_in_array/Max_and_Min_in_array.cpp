// Max_and_Min_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

void max_min(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "max = " << max << endl;
    cout << "min = " << min << endl;
}

int main()
{
    int arr[5] = { 10,3,2,60,-1};
    int size = sizeof(arr) / sizeof(arr[0]);
    max_min(arr, size);
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
