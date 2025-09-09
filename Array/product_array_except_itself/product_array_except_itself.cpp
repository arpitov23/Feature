// product_array_except_itself.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> prod(vector <int>& arr)
{
    int n = arr.size();
    vector<int> res(n, 1);

    // calculate product of all element to left of each index
    int left_product = 1;
    
    for (int i = 0; i < n; i++)
    {
        res[i] = left_product;
        left_product = left_product * arr[i];

    }

    // multiply with product of all element to right
    int right_product = 1;

    for (int i = n-1; i >=0; i--)
    {
        res[i] = res[i] * right_product;
        right_product = right_product * arr[i];
    }
    return res;
}

int main()
{
    vector <int> num = { 1,2,3,4,5 };
    vector <int> res = prod(num);
    for (auto i : res)
        cout << i << " ";
    return 0;
}

