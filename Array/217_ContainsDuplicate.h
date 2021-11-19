#pragma once
#include <vector>
#include <unordered_set>

// https://leetcode.com/problems/contains-duplicate/

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Difficulty: Easy

namespace ContainsDuplicate {

	class Solution {

    public:
        bool containsDuplicate(std::vector<int>& nums) {
            // Store in set and check if set contains number
            std::unordered_set<int> hash_set;
            for(const auto& val : nums) {
	            if(hash_set.count(val) > 0) {
                    return true;
	            }
                hash_set.emplace(val);
            }
            return false;
        }
    };

} // namespace ContainsDuplicate