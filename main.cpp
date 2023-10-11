#include "sma.h"
#include <iostream>
#include <vector>
#include <numeric>


int main() {
    {
        int arrSize = 10;
        int windowSize = 2;
        auto arr = std::vector<double>(arrSize);
        std::iota(arr.begin(), arr.end(), 0);
        auto average = sma::simpleMovingAverage<double>(arr, windowSize);
        sma::printArr(arr);
        sma::printArr(average);
        auto arrf = std::vector<float>(arrSize);
        std::iota(arrf.begin(), arrf.end(), 10);
        sma::printArr(arrf);
        sma::printArr(sma::simpleMovingAverage<float>(arrf, windowSize + 2));
    }
    return 0;
}
