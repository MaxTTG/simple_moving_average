#include "sma.h"
#include <iostream>
#include <vector>


int main() {
    {
        int arrSize = 10;
        int windowSize = 2;
        auto arr = std::vector<double>(arrSize);
        auto arrf = std::vector<float>(arrSize);
        std::iota(arr.begin(), arr.end(), 0);
        std::iota(arrf.begin(), arrf.end(), 10);

        auto average = sma::simpleMovingAverage<double>(arr, windowSize);
        std::cout << "Double arr: ";
        sma::printArr<double>(arr);
        std::cout << "SMA result, windowSize = 2: ";
        sma::printArr<double>(average);


        auto averagef = sma::simpleMovingAverage<float>(arrf, windowSize * 2);
        std::cout << "\nFloat arr: ";
        sma::printArr<float>(arrf);
        std::cout << "SMA result, windowSize = 4: ";
        sma::printArr<float>(averagef);
    }

    sma::stdbm();

    return 0;
}
