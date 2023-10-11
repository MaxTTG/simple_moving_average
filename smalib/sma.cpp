#include "sma.h"

void sma::stdbm(int countAverage, int arrSize) {
    auto floatArr = sma::generateArr<float>(arrSize);
    auto doubleArr = sma::generateArr<double>(arrSize);

    const int wSizes[6] = {4, 8, 16, 32, 64, 128};
    std::vector<std::vector<long double>>bm(2, std::vector<long double>(6, 0));

    for (int i = 0; i < 6; ++i) {
        for (int j = countAverage; j; --j) {
            auto start = std::chrono::high_resolution_clock::now();
            sma::simpleMovingAverage<float>(floatArr, wSizes[i]);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            bm[0][i] += arrSize / duration.count();

            start = std::chrono::high_resolution_clock::now();
            sma::simpleMovingAverage<double>(doubleArr, wSizes[i]);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            bm[1][i] += arrSize / duration.count();
        }
    }
    std::cout << "\n\t";
    for (auto size : wSizes) std::cout << size << "\t\t";
    std::cout << "\nfloat:";
    for (auto t : bm[0]) std::cout << '\t' << t / countAverage;
    std::cout << "\ndouble:";
    for (auto t : bm[1]) std::cout << '\t' << t / countAverage;
    std::cout << std::endl;
}
