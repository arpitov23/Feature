// leader_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Problem Statement - leader in the array 
Description - Leader mean ?

    Leader mean is everything on the right should be smaller
    Ex - input : {10,22,12,3,0,6}
         output : {22,12,6}

*/

#include <iostream>
using namespace std;

void find_leader(int arr[], int& n)
{
    //int leaders[n]; // error - Instead of using int leaders[n];, dynamically allocate memory using new: 

    int* leaders = new int[n];   //temporary array to store leader
    int count = 0; // keep track of number of leaders

   

    int max_right = arr[n - 1]; // last element is always a leader 
    leaders[count++] = max_right;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_right)
        {
            max_right = arr[i];
            leaders[count++] = max_right;
        }
    }
    // ---- After for loop element stored in - {6,12,22} - but someone requirement is like to print in reverse order then below code is required.
    // printing in reverse order (since we traverse from right to left)

    for (int i = count - 1; i >= 0; i--)
    {
        cout << leaders[i] << " ";
    }


}
int main()
{
    int arr[] = { 16, 17, 4, 3, 5, 2 };  // output - 17 5 2 
    int n = sizeof(arr) / sizeof(arr[0]);
    find_leader(arr, n);
    return 0;
}

/*

 Use cases - 

 I/p =  16, 17, 4, 23,4,3, 5, 2 ,19,0,-1,8
 O/p = 23 19 8 

 I/p = 16, 17, 4, 23,4,3, 5, 2 ,189,0,-1,8
 O/p = 189 8 


*/