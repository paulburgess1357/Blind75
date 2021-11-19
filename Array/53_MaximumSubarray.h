#pragma once
#include <vector>

// https://leetcode.com/problems/maximum-subarray/

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Difficulty: Easy

namespace MaximumSubarray {

    class Solution {

    public:
        // Time Complexity: O(n^2)
		// Space Complexity: O(1)
        int maxSubArray(std::vector<int>& nums) {
            int maxSubArray = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                int currentSubArray = 0;
                for (int j = i; j < nums.size(); j++) {
                    currentSubArray += nums[j];
                    maxSubArray = std::max(maxSubArray, currentSubArray);
                }
            }
            return maxSubArray;
        }

        // Time Complexity: O(n)
        // Space Complexity: O(1)
        // See: Kadane's Algorithm
        int maxSubArray2(const std::vector<int>& nums) {
            // Set Max and Current as first element:
            int maxSubArray = nums.at(0);
            int currentBestSubArrayUpToThisPoint = nums.at(0);
            for (int i = 1; i < nums.size(); i++) {
                currentBestSubArrayUpToThisPoint = std::max(nums.at(i), currentBestSubArrayUpToThisPoint + nums.at(i));
                maxSubArray = std::max(currentBestSubArrayUpToThisPoint, maxSubArray);
            }
            return maxSubArray;
        }

    };

} // namespace MaximumSubarray
