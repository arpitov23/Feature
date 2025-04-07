// Third_largest_element_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int third_largest(int arr[], int n)
{

	if (n < 3)
		return INT_MIN;

	int largest = INT_MIN;
	int second_largest = INT_MIN;
	int third_largest = INT_MIN;


	for (int i = 0; i< n; i++)
	{
		if (arr[i] > largest)
		{
			third_largest = second_largest;
			second_largest = largest;
			largest = arr[i];
		}
		else if (arr[i] > second_largest && arr[i] != largest)
		{
			third_largest = second_largest;
			second_largest = arr[i];
		}
		
		else if (arr[i] > third_largest && arr[i] != second_largest && arr[i] != largest)
		{
			third_largest = arr[i];
		}

	}
	return third_largest;
}
int main()
{
	int arr[] = { 12, 35, 1, 10, 34, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int thirdLargest = third_largest(arr, n);

	if (thirdLargest != INT_MIN) {
		cout << "The third largest element is: " << thirdLargest << endl;
	}
	else {
		cout << "Third largest element not found." << endl;
	}

	return 0;
}

/*
---------------   Explanation --------------


Explanation:
Initial Values:

We initialize three variables: largest, secondLargest, and thirdLargest to INT_MIN to handle comparisons properly.

Single Pass Through Array:

For each element in the array, we check if it's greater than the largest value. If so, we shift the current values:

	thirdLargest = secondLargest
	secondLargest = largest
	largest = current element

If the element is not larger than largest, but it is larger than secondLargest, we update:

	thirdLargest = secondLargest
	secondLargest = current element

Similarly, if the element is not larger than secondLargest, but it is larger than thirdLargest and not equal to the largest or second largest, we update thirdLargest

*/

/*
--------------  Dry Run -------------

Iteration 1 (i = 0): Current element: 12

	12 > largest (INT_MIN), so:

	thirdLargest = secondLargest = INT_MIN

	secondLargest = largest = INT_MIN

	largest = 12

	Updated values: largest = 12, secondLargest = INT_MIN, thirdLargest = INT_MIN

Iteration 2 (i = 1): Current element: 35

	35 > largest (12), so:

	thirdLargest = secondLargest = 12

	secondLargest = largest = 12

	largest = 35

	Updated values: largest = 35, secondLargest = 12, thirdLargest = 12

Iteration 3 (i = 2): Current element: 1

	1 is not greater than largest (35) or secondLargest (12), so no changes.

	Updated values: largest = 35, secondLargest = 12, thirdLargest = 12

Iteration 4 (i = 3): Current element: 10

	10 is not greater than largest (35) or secondLargest (12), so no changes.

	Updated values: largest = 35, secondLargest = 12, thirdLargest = 12

Iteration 5 (i = 4): Current element: 34

	34 > secondLargest (12), but not greater than largest (35), so:

	thirdLargest = secondLargest = 12

	secondLargest = 34

	Updated values: largest = 35, secondLargest = 34, thirdLargest = 12

Iteration 6 (i = 5): Current element: 1

	1 is not greater than largest (35) or secondLargest (34) or thirdLargest (12), so no changes.

	Final values: largest = 35, secondLargest = 34, thirdLargest = 12

Note : The third largest element is: 12


*/