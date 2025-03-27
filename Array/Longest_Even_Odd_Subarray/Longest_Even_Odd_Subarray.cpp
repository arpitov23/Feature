#include <iostream>
using namespace std;

void evenodd_mathKadane(int arr[], int size) {
    int ans = 0;
    int count = 1;
    for (int i = 1; i < size; i++) {
        if ((arr[i - 1] + arr[i]) % 2 != 0) { // extending the same subarray
            count++;
            ans = max(ans, count);
        }
        else count = 1; // choosing the new subarray
    }
    cout << "The length of the longest even-odd subarray is " << ans;
}
int main() {
    int arr[] = { 1,2,130,4,5,7,9 };
    int size = 7;
    evenodd_mathKadane(arr, size);
    return 0;
}

/*

Explanation - 

The function evenodd_mathKadane() is intended to find the length of the longest "even-odd subarray," 
where "even-odd" means that the sum of every two consecutive elements in the subarray is odd. 
This can happen when one element is even and the next is odd (or vice versa).

Dry Run:
Initial Values:

arr[] = { 1, 2, 130, 4, 5, 7, 9 }

size = 7

ans = 0 (to keep track of the longest subarray length)

count = 1 (this will count the length of the current subarray)

Iteration 1 (i = 1):
arr[i-1] = arr[0] = 1, arr[i] = arr[1] = 2

Sum: 1 + 2 = 3, which is odd (3 % 2 != 0).

Since the sum is odd, we extend the current subarray.

count = count + 1 = 2

ans = max(ans, count) = max(0, 2) = 2

Iteration 2 (i = 2):
arr[i-1] = arr[1] = 2, arr[i] = arr[2] = 130

Sum: 2 + 130 = 132, which is even (132 % 2 == 0).

Since the sum is even, we reset count = 1 (start a new subarray).

Iteration 3 (i = 3):
arr[i-1] = arr[2] = 130, arr[i] = arr[3] = 4

Sum: 130 + 4 = 134, which is even (134 % 2 == 0).

Sum is even again, so we reset count = 1.

Iteration 4 (i = 4):
arr[i-1] = arr[3] = 4, arr[i] = arr[4] = 5

Sum: 4 + 5 = 9, which is odd (9 % 2 != 0).

Sum is odd, so we extend the current subarray.

count = count + 1 = 2

ans = max(ans, count) = max(2, 2) = 2

Iteration 5 (i = 5):
arr[i-1] = arr[4] = 5, arr[i] = arr[5] = 7

Sum: 5 + 7 = 12, which is even (12 % 2 == 0).

Sum is even, so we reset count = 1.

Iteration 6 (i = 6):
arr[i-1] = arr[5] = 7, arr[i] = arr[6] = 9

Sum: 7 + 9 = 16, which is even (16 % 2 == 0).

Sum is even, so we reset count = 1.

Final Calculation:

The longest even-odd subarray found has a length of 2 (ans = 2).

*/