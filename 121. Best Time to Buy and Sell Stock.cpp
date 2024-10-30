/**
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
#if 0
        /* Intuitive but O(n^2) */
        int32_t maxProfit = 0, profit = 0;
        for(uint32_t i=0; i<prices.size(); i++)
        {
            for(uint32_t j=i; j<prices.size(); j++)
            {
                profit = prices[j] - prices[i];
                if(maxProfit < profit)
                {
                    maxProfit = profit;
                }
            }
        }
#endif
        uint32_t i;
        int maxProfit = 0, min = 10000, profit = 0;

        for(i = 0; i < prices.size(); i++)
        {
            /**
             * Always find the smallest value during traversing since it has potential to get the max profit.
             * But the smallest value may not earn the max profit, so we need to record the max profit ever.
             */
            if(min > prices[i])
                min = prices[i];
            else
                profit = prices[i] - min;
            
            if(maxProfit < profit)
                maxProfit = profit;
        }

        return maxProfit;
    }
};