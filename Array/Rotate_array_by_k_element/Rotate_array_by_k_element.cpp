#include <iostream>
using namespace std;

void array_reverse(int arr[], int start, int end)
{
	while (start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

// step for right rotation or clock-wise

//	Reverse an entire array
//  Reverse first k element
//  Reverse n-k element 

void right_rotate(int arr[], int n, int k)
{
	k = k % n;  // handle k > n 

	// reverse entire array
	array_reverse(arr, 0, n - 1);  // {50,40,30,20,10}
	
	// reverse first k element 
	array_reverse(arr, 0, k-1);  // {40,50,30,20,10}
	

	// reverse n-k element 
	array_reverse(arr, k, n - 1); // output - {40, 50, 10, 20, 30,}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ", ";
	cout << "\n============\n";
}


// step for left rotation or anticlock-wise

// Reverse first k element 
// Reverse the remaining n-k element 
// Reverse the entire array 

void left_rotation_anticlockwise(int arr[], int n, int k)
{
	k = k % n; // handle k > n

	// reverse first k element 
	array_reverse(arr, 0, k - 1);   // {20,10,30,40,50}
	
	// reverse n-k element 
	array_reverse(arr, k, n - 1);   // {20, 10, 50, 40, 30,}

	// reverse entire array
	array_reverse(arr, 0, n - 1);   // output- 30, 40, 50, 10, 20,

}


int main()
{
	int arr[] = { 10,20,30,40,50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	//array_reverse(arr, 0, n - 1);
	right_rotate(arr, n, k);         // output - {40,50,10,20,30}
	//left_rotation_anticlockwise(arr, n, k);
	for (int i = 0; i < n; i++)
	cout << arr[i] << ", " ;

	return 0;
}