// Container_with_most_water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

------------  Important point -------------

1. Every vertical line is equally spread by 1 unit.
2. 2 variable define container size - left & right and width
3. Volume of water = min(left, right) * width ------------------------- width - distance between 2 index or heigth
4. 1 bar will always be included in full (amount of left and right)

/*
------- Problem Statement ------------

The Container with Most Water problem is a classic problem. The goal is to find the maximum area between two lines in an array of heights, 
where the lines are drawn between indices of the array. The container’s area is determined by the shorter of the two lines and the distance between them.

Problem Statement - 
You are given an array of non-negative integers where each element represents the height of a line drawn at that index. The width between each pair of 
lines is the difference in their indices. Your task is to find the maximum area that can be formed between two lines.

The area between two lines is calculated as : Area = min( height[i], height[j] * (j-i)) , where i and j are indices of the two lines.

------------ approach : Two-pointer approach: ----------

Ques - Why 2 pointer ?
Answ - At least 1 bar (smaller of 2 ) is included till it's full height.

-> Start with two pointers: one at the beginning (left) and one at the end (right) of the array.
-> Calculate the area between the lines at the left and right pointers.
-> Move the pointer pointing to the shorter line inward, as this could potentially increase the area (since the area is limited by the shorter of the two lines).
-> Repeat the process until the pointers meet.


----------- Complexity ------------

Time complexity : 
O(n), where n is the number of elements in the array. We only need a single pass through the array using the two-pointer technique.

Space Complexity:
O(1), as we are only using a few extra variables for the pointers and the result.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int container_with_most_water(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right)
    {
        // calculate the area with the current left and right pointer

        int width = right - left;
        int current_area = min(height[left], height[right]) * width;

        // update the max area found 
        max_area = max(max_area, current_area);

        // Move the pointer pointing to the shorter line inward

        if (height[left] < height[right])
        {
            left++;
        }
        else
            right--;
    }
    return max_area;
}
int main()
{
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    cout << "The maximum area is: " << container_with_most_water(height) << endl;
    return 0;
}


/*

-------- Explanation -----------

1. Two-Pointer :
        We start with 2 pointer - one at begining (left = 0) and one at end (right = height.size()-1).

2. Area Calculation :
         At each step, the area betweeen the line at indices left and right is calcualted as:
           Area = min(height[left], height[right] * (right-left))

         We then update the "max_area" if the current area is larger than the previous maximum.

3. Pointer Movement :

      We move the pointer pointing to the shorter line inward, because moving the shorter line might increase the area, whereas moving the taller line will not help.

4. Repeat the process until the pointer meet. 
*/


/*

---------- Dry Run ---------------

Dry Run:
Initial State:

    left = 0, right = 8
    max_area = 0

First iteration:

    current_area = min(1, 7) * (8 - 0) = 8
    max_area = max(0, 8) = 8
    Since height[left] < height[right], increment left to 1.

Second iteration:

    current_area = min(8, 7) * (8 - 1) = 7 * 7 = 49
    max_area = max(8, 49) = 49
    Since height[left] > height[right], decrement right to 7.

Continue this process until left and right meet, and the largest area found is 49.


---------- Note -------------
The two-pointer technique is an efficient solution for this problem, and it works in linear time. 
By always moving the shorter pointer inward, we are guaranteed to find the maximum area.


*/