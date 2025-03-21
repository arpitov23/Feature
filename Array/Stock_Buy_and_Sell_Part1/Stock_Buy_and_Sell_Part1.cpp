// Stock_Buy_and_Sell_Part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//The Stock Buy and Sell Problem (Part 1) involves determining the maximum profit that can be made by buying and selling 
// stocks on different days, given a list of prices. 
// // You can only perform one transaction (buy once and sell once).

/*
   Problem Description - 
   -> You are given an array prices[] where prices[i] is the price of a stock on the ith day.
   -> You need to find the maximum profit you can achieve by buying and selling the stock once.

     NOTE -     You can only buy the stock on one day and sell it on a later day.
     NOTE -     The stock price can increase or decrease each day, but you can only make one buy and one sell transaction.


   Approach - calculate the profit for each day based on the current price and the minimum price.

   Steps:
    Initialize two variables:

        min_price to store the lowest price encountered so far.
        max_profit to store the maximum profit.

    Iterate through the array:

     For each price:
       -> Calculate the profit if we were to sell the stock at the current price.
       -> Update max_profit if the current profit is greater than the previously recorded max_profit.
       -> Update min_price if the current price is lower than the min_price.
       -> Return max_profit after the loop completes.


*/


#include "pch.h"
#include <iostream>
using namespace std; 

int max_profit(int arr[], int size)
{
    if (size < 2)
        return 0; // if there are fewer than 2 prices, no transaction can be made

   // Initialize min price to the maximum integer value and max profit to 0.

    int min_price = arr[0];
    int max_profit = 0;

    // Iterate through each price in the array 

    for (int i = 0; i < size; i++)
    {
        // update min_price - if lower price found 
        if (arr[i] < min_price)
        {
            min_price = arr[i];
        }

        int profit = arr[i] - min_price; // calculate profit - if we sell at current price

        // update max_profit - if current profit is greater than max profit

        if (profit > max_profit)
        {
            max_profit = profit;
        }
    }
    return max_profit;
}
int main()
{
    int prices[] = { 7, 1, 5, 3, 6, 4 };
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Maximum Profit: " << max_profit(prices, n) << endl;

    return 0; 
    
}


