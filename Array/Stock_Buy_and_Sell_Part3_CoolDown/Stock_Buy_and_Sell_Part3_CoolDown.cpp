// Stock_Buy_and_Sell_Part3_CoolDown.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

   Cooldown - You cannot buy stock on the next day of sell 

   Input: arr[] = {1, 2, 3, 0, 2}
	Output : 3
	Explanation: You first buy on day 1, sell on day 2 then cool down, then buy on day 4, and sell on day 5. 
				  The total profit earned is (2-1) + (2-0) = 3, which is the maximum achievable profit.


	Input: arr[] = {3, 1, 6, 1, 2, 4}
	Output: 7
	Explanation: You first buy on day 2 and sell on day 3 then cool down, then again you buy on day 5 and then sell on day 6. 
				  Clearly, the total profit earned is (6-1) + (4-2) = 7, which is the maximum achievable profit.

*/


#include <iostream>
using namespace std;

int max_profit_with_cooldown(int arr[], int n)
{
	if (n == 0)
		return 0;

	int hold = -arr[0]; // We buy on day 0
	int not_hold = 0; // No profit on day 0 , when not holding any stock 
	int cool_down = 0; // No cooldown profit on day 0

	// Traverse through rest of the days 

	for (int i = 1; i < n; i++)
	{
		int prev_hold = hold;
		int prev_not_hold = not_hold;
		int prev_cool_down = cool_down;


		// update the state transition

		hold = max(prev_hold, prev_not_hold - arr[i]); // Buy or hold the stock
		not_hold = max(prev_hold, prev_cool_down); // Do nothing or transition from cooldown
		cool_down = prev_hold + arr[i];
	}

	// The result is the maximum profit from not holding stock or being in cooldown on the last day

	return max(not_hold, cool_down);
}
int main()
{
	int v[] = { 3, 1, 6, 1, 2, 4 }; // Array representing stock prices
	int n = sizeof(v) / sizeof(v[0]);

	// Function call
	cout << max_profit_with_cooldown(v, n) << endl;
	return 0;
}
