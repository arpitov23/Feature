#include <iostream>
using namespace std;


/*
 Solution - 2 pointer

 Two Pointers
Solution 1 and 2 work for the unsorted arrays also, The arrays arr1 and arr2 are sorted, can we use this property to reduce the time Complexity?

Using the property that the arrays are sorted we can bring down the time complexity from

O((m+n)log(m+n))    TO    O(m+n).

Approach:
Take two pointers let’s say i,j pointing to the 0th index of arr1 and arr2.
Create an empty vector for storing the union of arr1 and arr2.
From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2
Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the union vector.
While traversing we may encounter three cases.

arr1[ i ] == arr2[ j ]
Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i.

NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we are inserting
duplicates which is not desired. So while inserting always check whether the last element in the union vector is equal or
not to the element to be inserted. If equal we are trying to insert duplicates, so don’t insert the element, else insert
the element in the union. This makes sure that we are not inserting any duplicates in the union because we are inserting
elements in sorted order.

arr1[ i ]  < arr2[ j ]

arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to 
arr1[ i ],then insert in union else don’t insert. After checking Increment i.
arr1[ i ] > arr2[ j ]

arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is 
not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After traversing 
if any elements are left in arr1 or arr2 check for condition and insert in the union.

*/

int FindUnion(int arr1[], int arr2[], int n, int m, int result[]) {
    int i = 0, j = 0; // pointers
    int unionSize = 0; // Keep track of union array size

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            // Add element if it's the first element or different from the last added element
            if (unionSize == 0 || result[unionSize - 1] != arr1[i]) {
                result[unionSize] = arr1[i];
                unionSize++;
            }
            i++;
        }
        else {
            if (unionSize == 0 || result[unionSize - 1] != arr2[j]) {
                result[unionSize] = arr2[j];
                unionSize++;
            }
            j++;
        }
    }

    // Process remaining elements of arr1
    while (i < n) {
        if (unionSize == 0 || result[unionSize - 1] != arr1[i]) {
            result[unionSize] = arr1[i];
            unionSize++;
        }
        i++;
    }

    // Process remaining elements of arr2
    while (j < m) {
        if (unionSize == 0 || result[unionSize - 1] != arr2[j]) {
            result[unionSize] = arr2[j];
            unionSize++;
        }
        j++;
    }

    return unionSize; // Return the size of union array
}

int main() {
    int n = 10, m = 7;
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr2[] = { 2, 3, 4, 4, 5, 11, 12 };

    // Create result array with maximum possible size (n + m)
    int k = n + m;
    int* result = new int[k];

    int unionSize = FindUnion(arr1, arr2, n, m, result);

    cout << "Union of arr1 and arr2 is " << endl;
    for (int i = 0; i < unionSize; i++) {
        cout << result[i] << " ";
    }

    return 0;
}