#pragma once
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/two-sum/

// Given an array of integers nums  and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

namespace TwoSum {

	class Solution {
	public:
		// Time Complexity: O(n^2)
		// Space Complexity: O(1)
		std::vector<int> twoSum1(const std::vector<int>& nums, const int target) {
			std::vector<int> result;
			for (int i = 0; i < nums.size(); i++) {
				int desiredNumber = target - nums[i];
				for(int j = i + 1; j < nums.size(); j++) {
					if(nums[j] == desiredNumber) {
						result.push_back(i);
						result.push_back(j);
						return result;
					}
				}
			}
			return result;
		}

		// Time Complexity: O(n)
		// Space Complexity O(n)
		std::vector<int> twoSum2(const std::vector<int>&nums, const int target) {
			std::vector<int> result;

			// Fill hash table and look up number to find:
			std::unordered_map<int, int> hashMap;
			for(int i = 0; i < nums.size(); i++) {
				int desiredNumber = target - nums[i];
				if(hashMap.count(desiredNumber) > 0) {
					result.push_back(i);
					result.push_back(hashMap[desiredNumber]);
					return result;
				}
				hashMap[nums[i]] = i;
			}
			return result;
		}
	};

} // namespace TwoSum