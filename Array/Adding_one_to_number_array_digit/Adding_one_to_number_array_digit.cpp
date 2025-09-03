// Adding_one_to_number_array_digit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> add_one(vector<int>&arr, int n)
{
    int end_index = n - 1;

    // while the end_index is valid and value at index is '9'.

    while (end_index > 0 && arr[end_index] == 9)
    {
        arr[end_index--] = 0;
    }
    // if index is < 0 (if all were 9)
    if (end_index < 0)
        // insert an one at the beginning of the vector
        arr.insert(arr.begin(), 1, 1);

    // else increment the value at [index]
    else
        arr[end_index]++;

    return arr;
    
}

int main()
{

    vector<int>arr = { 9,1,9,9,5 };  // output - 91996
   // vector<int>arr = { 9,9,9,9,9 };  // output - 100000
  //  vector<int>arr = { 9,1,9,9,9 };  // output - 92000 
   // vector<int>arr = { 0,0,0,0,0 };  // output - 00001 , 
    int n = arr.size();
    vector<int> res = add_one(arr, n);
    for(auto res_it :res)
    cout << res_it;
    return 0;
}
