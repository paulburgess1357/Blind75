#pragma once
#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/set-matrix-zeroes/

// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's, and return the matrix.
// You must do it in place.
// Difficulty: Medium

namespace SetMatrixZeros {

    class Solution {

    public:

        // Time Complexity O(MxN)
        // Space Complexity O(M+N)
        void setZeroes(std::vector<std::vector<int>>& matrix) {

            // matrix[row][col]

            // Iterate over the array and flag which rows/columns contain a zero:
            std::unordered_set<int> rowZero;
            std::unordered_set<int> colZero;

            size_t rowNum = matrix.size();
            size_t colNum = matrix.at(0).size();

            for(int row = 0; row < rowNum; row++) {
                for(int col = 0; col < colNum; col++) {
                    if(matrix[row][col] == 0) {
                        rowZero.insert(row);
                        colZero.insert(col);
                    }
                }
            }

            // Set all rows (flagged from above) to zero:
            for(const int row : rowZero) {
                for (int col = 0; col < colNum; col++) {
                    matrix[row][col] = 0;
	            }
            }

            // Set all columns (flagged from above) to zero:
            for(const int col : colZero) {
	            for(int row = 0; row < rowNum; row++) {
                    matrix[row][col] = 0;
	            }
            }
        }

    };

} // namespace SetMatrixZeros