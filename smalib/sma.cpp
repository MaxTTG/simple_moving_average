#include "sma.h"

/*
template<std::floating_point T>
std::vector<T> simpleMovingAverage(std::span<T> data, int windowSize) {
    auto smaArr = std::vector<T>(data.size() - windowSize + 1);
    T c = 1. / windowSize;
    smaArr[0] = std::accumulate(data.begin(), data.begin() + windowSize, 0) * c;

    auto smaArrPrev = smaArr.begin();
    auto dataPlus = data.begin() + windowSize;
    auto dataMinus = data.begin();
    for (T &t: std::span<T>(smaArr.begin() + 1, smaArr.end()))
        t = *(smaArrPrev++) + (*(dataPlus++) - *(dataMinus++)) * c;

    return smaArr;
}

template<std::floating_point T>
void printArr(std::vector<T> arr) {
    if (arr.begin() == arr.end()) {
        std::cout << "Vector is empty\n";
        return;
    }
    for (T t: arr)
        std::cout << t << " ";
    std::cout << '\n';
}

template<std::floating_point T>
std::vector<T> generateArr(int len) {
    auto arr = std::vector<T>(len);
    std::random_device rd;
    std::uniform_real_distribution<T> dist(0., 10.);
    for (T &t: arr)
        t = dist(rd);

    return arr;
}*/