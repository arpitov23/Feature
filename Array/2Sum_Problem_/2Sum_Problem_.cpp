#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

vector<int>twoSum(vector<int>&nums, int target)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (umap.find(complement) != umap.end())
        {
            return{ umap[complement], i }; // found the index
        }
        umap[nums[i]] = i; // store the current number with its index
    }
    return {};// return empty , if no solution found
}


/*string twoSum(int n, vector<int>& arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
*/
int main()
{
    int n = 5;
    vector<int> arr = { 2, 6, 5, 8, 11 };
    int target = 14;
   vector<int>ans = twoSum( arr, target);

   if (!ans.empty())
    cout << "This is the answer for index: " << ans[0] <<" & "<<ans[1] << endl;
    return 0;
}

/* Dry Run

 Input - 2, 6, 5, 8, 11 
 Target - 14
 Ouput - index 1 & 3
 
 Initialization:

    numMap = {} (empty at the start)
 
 
 Iteration 1 (i = 0):

   nums[0] = 2

   complement = 14 - 2 = 12

   Check if 7 exists in numMap → No

    Add 2 to numMap: {2: 0}

Iteration 2 (i = 1):

   nums[1] = 6

   complement = 14 - 6 = 8

   Check if 8 exists in numMap → Yes (found at index 3)

   Return indices [3, 1]
 
 
 */


/*
 INput - {2,6,5,8,11}
 target - 11 

 Initialization:

numMap = {} (empty at the start)

Iteration 1 (i = 0):

        nums[0] = 2

        complement = 11 - 2 = 9

        Check if 9 exists in numMap → No

        Add 2 to numMap: {2: 0}

Iteration 2 (i = 1):

        nums[1] = 6

        complement = 11 - 6 = 5

        Check if 5 exists in numMap → No

        Add 6 to numMap: {2: 0, 6: 1}

Iteration 3 (i = 2):

        nums[2] = 5

        complement = 11 - 5 = 6

        Check if 6 exists in numMap → Yes (found at index 1)

Return indices [1, 2]
 

*/
 