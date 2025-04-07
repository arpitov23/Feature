// Maximum_Product_of_triplet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int max_product_triplet(int arr[], int n)
{
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // update largest 3 values

        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }

        else if (arr[i] < max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
        {
            max3 = arr[i];
        }

        //update smallest 2 values

        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
        {
            min2 = arr[i];
        }
    }

    // step3 = calculate 2 potentional max products

    int product1 = max1 * max2 * max3; // Product of the three largest numbers
    int product2 = min1 * min2 * max1; // Product of the two smallest and the largest number

    // Step 4: Return the maximum of both products
    return max(product1, product2);

}

int main()
{
   int  arr[] = {1, 10, -5, 1, -100};
   int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Product of a Triplet: " << max_product_triplet(arr,n) << endl;

    return 0;
}
