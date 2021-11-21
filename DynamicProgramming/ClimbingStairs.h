#pragma once
#include <vector>

// https://leetcode.com/problems/climbing-stairs/solution/

// You are climbing a stair case.It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top?
// Difficulty: Easy
// The solution below isn't dynamic programming!! TODO: Add DP solution

namespace ClimbingStairs {

    class Solution {

    public:
        // Time Complexity: O(2^N)
        // Space Complexity: O(N)
        int climbStairs(int totalSteps) {
            // This function will recursively add (+1) for all valid paths encountered
            return isStepPathValid(0, totalSteps);
        }

    private:
        int isStepPathValid(int currentStep, int destinationStep) {

            // If our current step goes past our destination step, it means we
            // have calculated an invalid path.  For example, say we are taking
            // 2 steps, and the total number of steps is 3.  First we are on
            // step 0.  Our first step puts on on 2.  Our second step puts us
            // on step 4.  This is invalid, so we return 0.
        	if(currentStep > destinationStep) {
                return 0;
	        }

            // If our current step equals our destination step, it means we
            // arrived there correctly.  For example, if there are 4 steps and
            // we take 2 at a time.  0 -> 2; 2->4.  We have arrived correctly,
            // so we keep track of this path by returning a 1 (to later sum up
            // indicating it was valid).
            if(currentStep == destinationStep) {
                return 1;
            }

            // We recursively run this function with the step possibilities:
            // E.g. 1 step or 2 steps.
            return isStepPathValid(currentStep + 1, destinationStep) + isStepPathValid(currentStep + 2, destinationStep);
        }

    };

} // namespace ClimbingStairs