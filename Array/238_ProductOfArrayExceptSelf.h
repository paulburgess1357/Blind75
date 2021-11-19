#pragma once
#include <vector>

// https://leetcode.com/problems/product-of-array-except-self/

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.
// Difficulty: Medium

namespace ProductOfArray {

    class Solution {
    public:

        // Time Complexity: O(n)
        // Space Complexity: O(n)
        std::vector<int> productExceptSelf(std::vector<int>& nums) {

            std::vector<int> lhs;
            lhs.resize(nums.size());

            std::vector<int> rhs;
            rhs.resize(nums.size());

            // Construct lhs vector
            // This vector contains the product of all values in the array
            // as you traverse the array left to right
            // [4, 5, 8]
            // [1, 4, 20]
            lhs[0] = 1; // Set first element to 1
            for (int i = 1; i < nums.size(); i++) {
                lhs[i] = lhs[i - 1] * nums[i - 1];
            }

            // Construct the rhs vector
            // This vector contains the product of all values int the array
            // as you traverse the array right to left
            // [4,  5,  8]
            // [40, 8,  1]
            rhs[nums.size() - 1] = 1; // Set last element to 1
            for (int i = nums.size() - 2; i >= 0; i--) {
                rhs[i] = rhs[i + 1] * nums[i + 1];
            }

            // Construct the final vector:
            std::vector<int> result;
            result.reserve(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(lhs[i] * rhs[i]);
            }

            return result;
        }
    };

}