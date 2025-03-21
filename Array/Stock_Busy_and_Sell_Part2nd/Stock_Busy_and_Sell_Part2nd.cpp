// Stock_Busy_and_Sell_Part2nd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//The Stock Buy and Sell Problem (Part 2) extends the first problem where you are allowed to make multiple transactions to maximize profit. 
// Unlike the first part, where you are allowed only one transaction (buy once and sell once), in Part 2, you can buy and sell the stock multiple times, 
// but the goal is still to maximize profit.

/*
   Problem Description (Part 2):  

     ->   You are given an array of stock prices where prices[i] is the price of the stock on the ith day.
     ->   You are allowed to buy and sell the stock multiple times, but you must buy before you sell.
     ->   Your task is to find the maximum profit you can make by performing any number of transactions (buy and sell multiple times).

     Example - 
     Input: prices[] = {7, 1, 5, 3, 6, 4}
            Output:     7
                    ->    Buy on day 2 (price = 1), sell on day 3 (price = 5) → profit = 5 - 1 = 4.
                    ->    Buy on day 4 (price = 3), sell on day 5 (price = 6) → profit = 6 - 3 = 3.
                    ->    Total profit = 4 + 3 = 7.


    Approach:
        ->   To solve this problem optimally, we can iterate through the array and add profits whenever there is an increase in the 
             price of the stock (i.e., when prices[i + 1] > prices[i], indicating that we can make a profit by buying at prices[i] and selling at prices[i + 1]).

    Steps:
       ->     Initialize a variable profit to store the cumulative profit.
       ->     Iterate through the array:
       ->     Whenever the next day's price is higher than the current day's price, it means we can make a profit by buying on the current day and selling on the next day.
       ->     Add the difference between the two prices to profit.
       ->     Return the total profit after iterating through the entire array.

*/


#include "pch.h"
#include <iostream>
using namespace std;

int stock_buy_sell_max_profit(int arr[], int n)
{
    int max_profit = 0;

    // Iterate through the prices array 

    for (int i = 1; i < n; i++)        
    {
        // if the next day price is higher , we can profit by selling today 
        if (arr[i] > arr[i - 1])                         /// 100, 180, 260, 310, 40, 535, 695
        {
            cout << "arr[i] = " << arr[i] << " arr[i-1] = " << arr[i - 1] << endl;
            max_profit = max_profit + arr[i] - arr[i - 1];
            cout << "max_profit : " << max_profit << endl;
        }
    }

    return max_profit; 
}
int main()
{
    int prices[] = { 3, 2, 6, 5, 0, 3 };
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Maximum Profit: " << stock_buy_sell_max_profit(prices, n) << endl;

    return 0;
}


