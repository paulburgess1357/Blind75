#include <iostream>
#include "73_SetMatrixZeros.h"

int main()
{
    std::cout << "hi\n";
    std::vector<std::vector<int>> input{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };


    SetMatrixZeros::Solution test;
    test.setZeroes2(input);

    std::cout << "Hello World!\n";
}
