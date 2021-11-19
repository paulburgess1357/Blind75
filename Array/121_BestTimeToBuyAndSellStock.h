#pragma once
#include <vector>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.
// Difficulty: Easy

namespace BuyStock {

    class Solution {

    public:
        // Time Complexity: O(n^2)
        // Space Complexity: O(1)
        int maxProfit1(const std::vector<int>& prices) {
            int maxProfit = 0;
            for(int i = 0; i < prices.size(); i++) {
	            for(int j = i + 1; j < prices.size(); j++) {
                    int profit = prices[j] - prices[i];
                    if(profit > maxProfit) {
                        maxProfit = profit;
                    }
	            }
            }
            return maxProfit;
        }

        // Time Complexity: O(n)
	// Space Complexity: (1)
        int maxProfit2(const std::vector<int>& prices) {
            int lowestPrice = INT_MAX;
            int maxProfit = 0;
            for(int i = 0; i < prices.size(); i++) {
                if(prices[i] < lowestPrice) {
                    // Track lowest price encountered
                    lowestPrice = prices[i];
                } else {
	                // Compare current profit with maxProfit
                    maxProfit = std::max(maxProfit, prices[i] - lowestPrice);
                }
            }
            return maxProfit;
        }

    };

} // namespace BuyStock
