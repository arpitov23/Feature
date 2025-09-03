// Triplet_sum_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

bool triplet_sum(vector<int>&arr,int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        // initialize left and right pointer with start and end of remaining subarray
        int left = i + 1;
        int right = n - 1;

        int required_sum = target - arr[i];
        
        while (left < right)
        {
            if (arr[left] + arr[right] == required_sum) {
                std::cout << arr[left] << " " << arr[right] << " " << arr[i] << std::endl;
                return true;
            }
            
            if (arr[left] + arr[right] < required_sum)
                left++;

            else if (arr[left] + arr[right] > required_sum)
                right--;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = { 1, 4, 45, 6, 10,51, 9 ,8 };
   
    int target = 13;
    bool res = triplet_sum(arr, target);
    cout << "res = " << res << endl;
    return 0;
}

